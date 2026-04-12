#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<ll,ll>
#define vint vector<ll>
#define pb push_back
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
ll read(){
	ll g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const ll N=3005;
ll c[N][N],s[N][N],ci[N][N],n,ans,mod;
ll ksm(ll x,ll y,ll Mod){
	ll re=1;
	while(y){
		if(y&1)re=re*x%Mod;
		x=x*x%Mod;y>>=1;
	}return re;
}
ll solve(ll k){
	ll re=0;
	for(ll i=0;i<=k;i++)re=(re+s[k+1][i+1]%mod*ci[n-k][i]%mod)%mod;
	return re*c[n][k]%mod*ksm(2,ksm(2,n-k,mod-1),mod)%mod;
}
void init(ll n){
	for(ll i=0;i<=n;i++)c[i][0]=1;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	s[0][0]=1;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%mod;
	for(ll i=0;i<=n;i++){
		ci[i][0]=1,ci[i][1]=ksm(2,i,mod);
		for(ll j=2;j<=n;j++)ci[i][j]=ci[i][j-1]*ci[i][1]%mod;
	}
}
signed main(){
	n=read(),mod=read(),init(3e3+1);
	for(ll i=0;i<=n;i++)ans=(ans+(i&1?mod-1:1)*solve(i)%mod)%mod;
	return cout<<ans,signed();
}
/*
2 1000000007
3 1000000009
50 111111113
3000 123456791
*/