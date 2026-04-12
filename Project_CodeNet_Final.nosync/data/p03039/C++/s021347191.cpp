#include<algorithm>
#include<cstdio>
#define mxn 200010
#define LL long long
using namespace std;
const int mod=1e9+7;
int n,m,K,N,C,sl,fh,ans,inv[mxn];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int _pow(int k,int i)
{
	int t=1;
	while(i)
	{
		if(i&1) t=1ll*t*k%mod;
		k=1ll*k*k%mod;i>>=1;
	}
	return t;
}
int main()
{
	n=rd();m=rd();K=rd()-2;N=n*m-2;C=1;inv[1]=1;
	for(int i=N-K+1;i<=N;++i) C=1ll*i*C%mod;
	for(int i=2;i<=K;++i) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;;
	for(int i=2;i<=K;++i) C=1ll*C*inv[i]%mod;
	for(int i=1;i<n;++i) ans=(ans+1ll*i*(n-i)*m*m)%mod;
	for(int i=1;i<m;++i) ans=(ans+1ll*i*(m-i)*n*n)%mod;
	ans=1ll*C*ans%mod;
	printf("%d\n",ans);
	return 0;
}