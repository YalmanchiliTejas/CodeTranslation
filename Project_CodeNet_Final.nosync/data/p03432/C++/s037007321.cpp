#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<ll,ll>
#define vint vector<ll>
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
const ll mod=998244353;
const ll N=100005;
const ll M=205;
const ll maxn=100000;
ll fac[N],inv[N],n,m,wn[N];
vint h,g,f[M],na,nb;
ll ksm(ll x,ll y){
	ll re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;y>>=1;
	}return re;
}
void ntt(vint &a,ll n,ll opt){
	for(ll i=0;i<n;i++){
		ll j,k,m;
		for(k=i,m=1,j=0;m<n;m<<=1,j=(j<<1)|(k&1),k>>=1);
		if(i>j)swap(a[i],a[j]);
	}ll t0,t1;wn[0]=1;
	for(ll m=1;m<n;m<<=1){
		t0=ksm(3,mod-1+opt*(mod-1)/(m<<1));
		for(ll i=1;i<m;i++)wn[i]=wn[i-1]*t0%mod;
		for(ll st=0;st<n;st+=(m<<1))for(ll i=st;i<st+m;i++){
			t0=a[i],t1=a[i+m]*wn[i-st]%mod;
			a[i]=(t0+t1)%mod,a[i+m]=(t0-t1+mod)%mod;
		}
	}if(opt==1)return;
	ll inv=ksm(n,mod-2);
	for(ll i=0;i<n;i++)a[i]=a[i]*inv%mod;
}
void merge(vint&a,vint&b){
	ll n=a.size(),m=b.size(),L=n+m-1;
	ll len;for(len=1;len<L;len<<=1);
	na.clear(),na.resize(len);for(ll i=0;i<n;i++)na[i]=a[i];
	nb.clear(),nb.resize(len);for(ll i=0;i<m;i++)nb[i]=b[i];
	ntt(na,len,1),ntt(nb,len,1);
	for(ll i=0;i<len;i++)na[i]=na[i]*nb[i]%mod;
	ntt(na,len,-1);
	a.resize(L);for(ll i=0;i<L;i++)a[i]=na[i];
}
ll C(ll n,ll m){
	if(n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
	n=read(),m=read();
	fac[0]=1;for(ll i=1;i<=maxn;i++)fac[i]=fac[i-1]*i%mod;
	inv[1]=1;for(ll i=2;i<=maxn;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	inv[0]=1;for(ll i=1;i<=maxn;i++)inv[i]=inv[i]*inv[i-1]%mod;
	f[m].resize(n+1);for(int i=0;i<=n;i++)f[m][i]=C(n,i);
	for(ll i=m-1;i>=0;i--){
		h.resize(n+1);for(ll j=0;j<=n;j++)h[j]=inv[n-j+2];h[n]=0;
		g.resize(n+1);for(ll j=0;j<=n;j++)g[j]=f[i+1][j]*fac[j+2]%mod;
		merge(h,g);f[i].resize(n+1);
		for(ll j=0;j<=n;j++)f[i][j]=(h[n+j]*inv[j]%mod+f[i+1][j]*(C(j+1,2)+1)%mod)%mod;
	}return cout<<f[0][0],signed();
}
/*
3 2
*/