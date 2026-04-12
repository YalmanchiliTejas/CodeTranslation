#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pf printf
#define sf scanf
#define pn printf("\n");
#define pk printf(" ");
#define sfn scanf("%d",&n);
LL a[55]={1LL},p[55]={1LL};
LL solve(LL n,LL x)
{
	if(n==0&&x>=1)
	return 1;
	else  if(x<=0)
	return 0;
	else if(x<=1+a[n-1])
	    return solve(n-1,x-1);
	    else
	    return 1+p[n-1]+solve(n-1,x-2-a[n-1]);
	
}
int main()
{
LL T,n,x;
	scanf("%lld %lld",&n,&x);
for(int i=1;i<55;i++)
{
	a[i]=a[i-1]*2+3;
	p[i]=p[i-1]*2+1;
	}	
	
	printf("%lld",solve(n,x));
 } 