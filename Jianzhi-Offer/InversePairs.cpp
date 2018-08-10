//统计数组中的逆序对

int InversePairs(int* data,int length)
{
	if(data==NULL || length<0)
		return 0;
	
	int* copy=new int[length];
	for(int i=0;i<length;++i)
		copy[i]=data[i];
	
	int count=INversePairsCore(data,copy,0,length-1);
	delete[] copy;
	
	return count;
}

int InversePairsCore(int* data,int* copy,int start,int end)
{
	if(start==end)
	{
		copy[start]=data[start];
		return 0;
	}
	
	int length=(end-start)/2;
	int left=InversePairsCore(copy,data,start,start+length);
	int right=InversePairsCore(core,data,start+length+1,end);
	
	//i初始化为前半段最后一个下标
	int i=start+length;
	//j初始化为后半段最后一个数字下标
	int j=end;
	int indexCopy=end;
	int count=0;
	while(i>start && j>=start+length+1)
	{
		if(data[i]>data[j])
		{
			copy[indexCopy--]=data[i--];
			count+=j-start-length;
		}
		else
		{
			copy[indexCopy--]=data[j--];
			
		}
	}
	for(;j>=start;--i)
		copy[indexCopy--]=data[i];
	
	for(;j>=start+length+1;--j)
		copy[indexCopy--]=data[j];
	
	return left+right+count;
}
