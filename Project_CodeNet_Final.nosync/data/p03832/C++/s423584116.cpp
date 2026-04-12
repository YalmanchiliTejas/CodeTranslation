#include<cstdio>
#include<algorithm>
#define mod 1000000007
#define int long long
int n,a,b,c,d,f[10010],fac[10010],inv[10010];
int quickpow(int x,int y){
	if(y==0)return 1;
	if(y%2==0)return quickpow(x*x%mod,y/2);
	if(y%2==1)return quickpow(x*x%mod,y/2)*x%mod;
}
signed main(){
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=quickpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	f[0]=1;
	for(int i=a;i<=b;i++)
		for(int j=std::min(i*d,n);j>=i*c;j--)
			for(int k=c,now=quickpow(inv[i],c),M=j-c*i;k<=d&&M>=0;k++,M-=i,now=now*inv[i]%mod)
                (f[j]+=fac[j]*now%mod*inv[M]%mod*f[M]%mod*inv[k]%mod)%=mod;
    printf("%lld\n",f[n]);
}