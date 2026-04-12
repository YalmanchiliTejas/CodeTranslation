#include<cstdio>
#include<iostream>
using namespace std;
const int N=3e3+10;
int n,mod,ans,s[N][N],t[N],fac[N],inv[N],f[N],g[N][N];
inline int MOD(int x){x-=x>=mod? mod:0;return x;}
inline int Minus(int x){x+=x<0? mod:0;return x;}
inline void Add(int &x,int y){x+=y;x-=x>=mod? mod:0;}
inline int fas(int x,int p,int M){int res=1;while(p){if(p&1)res=1ll*res*x%M;p>>=1;x=1ll*x*x%M;}return res;}
inline void Preprocess(){
	fac[0]=1;for(register int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;for(register int i=2;i<=n;i++)inv[i]=(-1ll*mod/i*inv[mod%i]%mod+mod)%mod;
	for(register int i=2;i<=n;i++)inv[i]=1ll*inv[i-1]*inv[i]%mod;//注意long long的强制转换 
}
inline int C(int n,int m){if(n<0||m<0||n<m)return 0;return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main(){
	scanf("%d%d",&n,&mod);Preprocess();
	ans=fas(2,fas(2,n,mod-1),mod);s[0][0]=1;
	for(register int i=1;i<=n+1;i++)
		for(register int j=1;j<=i;j++)
			s[i][j]=MOD(s[i-1][j-1]+1ll*j*s[i-1][j]%mod);
	for(register int i=1;i<=n;i++)f[i]=fas(2,fas(2,n-i,mod-1),mod);
	for(register int i=1;i<=n;i++)
		for(register int j=0;j<=n;j++)
			g[i][j]=fas(fas(2,n-i,mod),j,mod);
	for(register int i=1;i<=n;i++)
		for(register int j=0;j<=i;j++)
			Add(t[i],1ll*s[i+1][j+1]*C(n,i)%mod*f[i]%mod*g[i][j]%mod);
	for(register int i=1;i<=n;i++)
		if(i&1)ans=Minus(ans-t[i]);else Add(ans,t[i]);
	printf("%d\n",ans);
	return 0;
}