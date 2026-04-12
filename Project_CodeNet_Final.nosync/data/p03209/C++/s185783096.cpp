#include <stdio.h>
long long  dfs(long long m,long long n);
long long count;
long long num[51];
long long x[51];
int main()
{
	int i;
	long long  m,n;
	
	x[0]=1;
	num[0]=1;
	for(i=1;i<=50;i++)
	{
		num[i]=num[i-1]*2+3;
		x[i]=x[i-1]*2+1;
	}
	while(scanf("%lld %lld",&m,&n)!=EOF)
	{
		count=0 ;
		if(m==0)
		{
			if(n==1){
				count=1;
			}else if(n==0){
				count=0;
			}
			
		}else {
			count = dfs(m,n);
		}
		
		printf("%lld\n",count);
		
	}
}

long long  dfs(long long m,long long  n)
{
	if(m==1){
		if(n==0||n==1){
			return 0;
		}else if(n==2||n==3||n==4){
			return n-1;
		}else if(n==5){
			return 3;
		}
	}else {
		if(n==1||n==0){
			return 0;
		}else if(n>1&&n<(num[m]/2+1)){
			return dfs(m-1,n-1);
		}else if(n>=num[m]/2+1&&n<num[m]){
			return x[m-1]+dfs(m-1,n-(num[m]/2+1))+1;
		}else if(n==num[m]){
			return x[m-1]+dfs(m-1,n-(num[m]/2+1)-1)+1;
		}
	}
	
	
}