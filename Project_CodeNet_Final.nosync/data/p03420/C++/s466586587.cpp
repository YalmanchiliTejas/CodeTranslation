#include<stdio.h>
long long ans,n,m;
main()
{
	scanf("%lld%lld",&n,&m);
	if(m==0) printf("%lld\n",n*n);
	else
	{
		for(int i=m+1;i<=n;i++) ans+=(n/i)*(i-m)+(n%i-m+1)*(n%i>=m?1:0);
		printf("%lld\n",ans);
	}
	return 0;
}