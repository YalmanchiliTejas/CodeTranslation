#include<cstdio>
#define chkmax(a,b) ((a)>(b)?(a):(b))
long long ans;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==0)return printf("%lld",n*n),0;
	for(register long long i=k+1;i<=n;++i)
	{
		if(n%i>=k)ans+=(n%i)-k+1;
		ans+=(i-k)*(n/i);
		//printf("%lld %lld %lld\n",(i-k),n%i,(n/i));
		//printf("%lld %lld %lld\n",i-k,((n-(i-1))/i)+1,(n-(n/i)*i-k));
		//ans+=chkmax((n-(n/i)*i-k),0);
		//ans+=(i-k)*(((n-(i-1))/i)+1);
		//if(n%i==0)
		//if(k==0)ans+=(i-k)*
		//ans+=n-(n+k)/i*i;
	}
	printf("%lld\n",ans);
}