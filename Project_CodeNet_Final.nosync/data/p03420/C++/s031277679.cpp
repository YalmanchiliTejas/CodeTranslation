#include<bits/stdc++.h>
using namespace std;
long long n,k,c,d,cnt=0,hsh[100005];
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==0)
	{
		printf("%lld",n*n);
	}else
	{
		for(int i=k+1;i<=n;i++)
		{
			c=n/i;
			d=n%i;
			cnt+=(i-k)*c;
			if(d>=k)
			{
				cnt+=(d-k)+1;
			}
			//printf("%d %d\n",cnt,i);
		}
		printf("%lld",cnt);	
	}
}