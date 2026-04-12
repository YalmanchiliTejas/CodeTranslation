#include<iostream> 
#include<algorithm> 
#include<cstdio> 
#include<string>
#include<cstring>
using namespace std; 
int main() 
{ 
 	int H,W;
 	int a[105][105],b[105][105];
 	memset(b,0,sizeof(b));
	 cin>>H>>W; 
	 int i,j;
	 char ch;
	 for(i=1;i<=H;i++)
	 	for(j=1;j<=W;j++)
	 	{
	 		cin>>ch;
	 		if(ch=='.')
	 		a[i][j]=0;
	 		else if(ch=='#')
	 		a[i][j]=1;
		 }
	for(i=1;i<=H;i++)
	{
		int sum=0;
		for(j=1;j<=W;j++)
		sum+=a[i][j];
		if(sum==0)
		for(j=1;j<=W;j++)
		b[i][j]=-1;
	}
	for(j=1;j<=W;j++)
	{
		int sum=0;
		for(i=1;i<=H;i++)
		sum+=a[i][j];
		if(sum==0)
		for(i=1;i<=H;i++)
		b[i][j]=-1;
	}
	for(i=1;i<=H;i++)
	{
		int sign=0;
		for(j=1;j<=W;j++)
	 	{
	 		if(a[i][j]==0&&b[i][j]==0)
	 		{
	 			printf(".");
	 			sign=1;
			 }
	 		else if(a[i][j]==1&&b[i][j]==0)
	 		{
	 			printf("#");
	 			sign=1;
			 }
		 }
		 if(sign)
		 printf("\n");
	}
	return 0; 
}
