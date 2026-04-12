#include<cstdio>
#include<cstring>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 10010
#define MOD 998244353
using namespace std;
typedef long long ll;
int dp[MAXN][MAXN];
char a[MAXN],b[MAXN];
int cnta,cntb;
ll fac[MAXN],ifac[MAXN];
ll ans;
ll fsp(ll x,int y){
	ll res=1;
	while(y){
		if(y&1)
			res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}	
	return res;
}
void prepare(){
	fac[0]=1;
	for(int i=1;i<=10000;i++)
		fac[i]=fac[i-1]*i%MOD;
	ifac[10000]=fsp(fac[10000],MOD-2);
	for(int i=10000;i>=1;i--)
		ifac[i-1]=ifac[i]*i%MOD;
}
ll C(int n,int m){
	return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;	
}
int main(){
	prepare();
	SF("%s%s",a,b);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]=='1'){
			if(b[i]=='1')
				cnta++;
			else
				cntb++;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<=cnta;i++)
		for(int j=1;j<=cntb;j++){
			if(i!=0)
				dp[i][j]=1ll*dp[i-1][j]*i%MOD*j%MOD;
			dp[i][j]=(dp[i][j]+1ll*dp[i][j-1]*j%MOD*j%MOD)%MOD;
		}
	//PF("{%d %d}\n",dp[0][1],dp[1][1]);
	for(int i=0;i<=cnta;i++){
		int les=cnta-i;
		//PF("{%d %lld %lld %lld}\n",dp[i][cntb],fac[les],C(cnta,les),C(cnta+cntb,les));
		ans=(ans+1ll*dp[i][cntb]*fac[les]%MOD*fac[les]%MOD*C(cnta,les)%MOD*C(cnta+cntb,les)%MOD)%MOD;
	}
	PF("%lld",ans);
}