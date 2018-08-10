//二叉搜索树的后续遍历序列

bool VerifySequenceOfBST(int sequence[], int length)
{
	if(sequence==null || length<=0)
		return false;
	
	int root=sequence[length-1];
	
	//在二叉搜索树中左子树的节点小于根节点
	int i=0;
	for(;i<length-1;i++)
	{
		if(sequence[i]>root)
			break;
	}
	
	//在二叉搜索树中右子树的结点大于根节点
	int j=i;
	for(;j<length-1;++j)
	{
		if(sequence[j]<root)
			return false;
	}
	//判断左子树是不是二叉搜索树
	bool left=true;
	if(i>0)
		left=VerifySequenceOfBST(sequence,i);
	
	//判断右子树是不是二叉搜索树
	bool right=true;
	if(i<length-1)
		right=VerifySequenceOfBST(sequence+i,length-i-1);
	
	return (left && right);
}
