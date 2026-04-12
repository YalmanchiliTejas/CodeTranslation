#include<iostream>
using namespace std;
int N;
int A[10][10],B[10][10],T[10][10];
main()
{
	cin>>N;
	for(;N--;)
	{
		for(int i=0;i<10;i++)for(int j=0;j<10;j++)cin>>A[i][j];
		for(int i=0;i<1<<10;i++)
		{
			for(int j=0;j<10;j++)for(int k=0;k<10;k++)T[j][k]=A[j][k],B[j][k]=0;
			for(int j=0;j<10;j++)
			{
				if(i>>j&1)
				{
					B[0][j]=1;
					T[0][j]^=1;
					T[1][j]^=1;
					if(j>0)T[0][j-1]^=1;
					if(j<9)T[0][j+1]^=1;
				}
			}
			for(int j=1;j<10;j++)
			{
				for(int k=0;k<10;k++)
				{
					if(T[j-1][k])
					{
						B[j][k]=1;
						T[j-1][k]^=1;
						T[j][k]^=1;
						if(k>0)T[j][k-1]^=1;
						if(k<9)T[j][k+1]^=1;
						if(j<9)T[j+1][k]^=1;
					}
				}
			}
			bool flag=true;
			for(int j=0;j<10;j++)if(T[9][j])flag=false;
			if(flag)
			{
				for(int j=0;j<10;j++)
				{
					for(int k=0;k<10;k++)cout<<B[j][k]<<(k==9?"\n":" ");
				}
				break;
			}
		}
	}
}

