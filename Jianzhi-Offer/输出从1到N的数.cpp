//大数输出问题；
void Print1ToMaxOfNDigits(int n)
{
	if(n<=0)
		return;
	
	char * number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';
	
	while(!Increment(number))
	{
		PrintNumber(number);
	}
	
	delete []number;
}

bool Increment(char *number)
{
	bool isOverflow=false;
	int nTakeOver=0;
	int nLength=strlen(number);
	
	for(int i=nLength-1;i>=0;i--)
	{
		int nSum=number[i]-'0'+nTakeOver;
		if(i==nLength-1)
			nSum++;
		
		if(nSum>=10)
		{
			if(i==0)
				isOverflow=true;
			else
			{
				nSum-=10;
				nTakeOver=1;
				number[i]='0'+nSum;
			}
		}
		else
		{
			number[i]='0'+nSum;
			break;
		}
	}
	
	return isOverflow;
}

void PrintNumber(char * number)
{
	bool isBeginning0=true;
	int nLength=strlen(number);
	
	for(int i=0;i<nLength;++i)
	{
		if(isBeginning0 && number[i]!='0')
			isBeginning0=false;
		
		if(!isBeginning0)
		{
			prinft("%c",number[i]);
		}
	}
	
	printf("\t");
}

////////////////改进的大数输出问题///////////
void Print1ToMaxOfNDigits(int n)
{
	if(n<=0)
		return;
	
	char* number=new char[n+1];
	number[n]='\0';
	
	for(int i=0;i<10;++i)
	{
		number[0]=i+'0';
		Print1ToMaxOfDigitsRecursively(number,n,0)
	}
	
	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index)  ////递归实现
{
	if(index==length-1)
	{
		PrintNumber(number);
		return;
	}
	
	for(int i=0;i<10;++i)
	{
		number[index+1]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number,length,index+1);
	}
}

