#include<bits/stdc++.h>
#define mod 998244353
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char A[10010],B[10010];
int dp[10010][5010],fact[10010],ifact[10010];
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int C(int n,int m){return 1ll*fact[n]*ifact[m]%mod*ifact[n-m]%mod;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",A+1);scanf("%s",B+1);
	int n=strlen(A+1),p=0,q=0;
	for(int i=1;i<=n;++i)p+=A[i]=='1'&&B[i]=='1',q+=A[i]=='1'&&B[i]=='0';
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[n]=pow(fact[n],mod-2);for(int i=n;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	for(int i=0;i<=q;++i)dp[0][i]=1ll*fact[i]*fact[i]%mod;
	for(int i=1;i<=p;++i)
		for(int j=1;j<=q;++j)
			dp[i][j]=(1ll*dp[i][j-1]*j%mod*j+1ll*dp[i-1][j]*i%mod*j)%mod;
	int ans=0;
	for(int i=0;i<=p;++i)ans=(ans+1ll*dp[p-i][q]*fact[i]%mod*fact[i]%mod*C(p,i)%mod*C(p+q,i))%mod;
	printf("%d\n",ans);
	return 0;
}

