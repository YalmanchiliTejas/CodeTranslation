#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int C[maxn][maxn],S[maxn][maxn],mod,f[maxn],g[maxn];
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int dic(int a,int b){return a-b<0?a-b+mod:a-b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b,int p=mod,int c=1){for(;b;b>>=1,a=1ll*a*a%p) if(b&1) c=1ll*c*a%p; return c;}
int main(){
	int n,ans=0;cin>>n>>mod;
	for(int i=C[0][0]=S[0][0]=1;i<=n+1;++i) {
		for(int j=C[i][0]=1;j<=i;++j) C[i][j]=add(C[i-1][j-1],C[i-1][j]),S[i][j]=add(S[i-1][j-1],mul(j,S[i-1][j]));
	}
	for(int i=0;i<=n;++i){
		int res=0;int t=qpow(2,qpow(2,n-i,mod-1)),bt=qpow(2,n-i),now=1;
		for(int j=0;j<=i;++j) res=add(res,mul(S[i+1][j+1],now)),now=mul(now,bt);
		f[i]=mul(res,mul(t,C[n][i]));
	}
	for(int i=0;i<=n;++i){
		if(i&1) ans=dic(ans,f[i]);
		else ans=add(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}