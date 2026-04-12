#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll g[10005],inv[10005],F[10005];
int f[10005][10005];
ll quick_pow(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1) ans=ans*a%mod;
	return ans;
}
char a[10005],b[10005];
int n,m;
int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
ll C(int n,int m){
	return F[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	inv[0]=F[0]=1;
	for(int i=1;i<=n;i++) F[i]=F[i-1]*i%mod,inv[i]=quick_pow(F[i],mod-2);
	for(int i=1;i<=n;i++) if(a[i]=='1'&&b[i]=='1') m++;
	int o=n;n=0;
	for(int i=1;i<=o;i++) if(a[i]=='1') n++;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=1;
		for(int p=1;p<i&&p<=m;p++){
			f[i][p]=add(f[i-1][p],1LL*f[i-1][p-1]*(i-p)%mod);
		}
	}
	g[0]=1;
	for(int i=1;i<=n;i++){
		for(int p=0;p<i;p++) g[i]=(g[i]+g[p]*inv[p])%mod;
		g[i]=g[i]*F[i-1]%mod;
	}
	ll ans=0;
	for(int i=0;i<=m;i++){
		ll sum=C(m,i)*g[i]%mod;
		ans=(sum*f[n-i][m-i]%mod*F[n-m]%mod*F[n-m]%mod*F[m-i]%mod*F[i]%mod*C(n,i)+ans)%mod;
	}
	printf("%lld",ans);
	return 0;
}