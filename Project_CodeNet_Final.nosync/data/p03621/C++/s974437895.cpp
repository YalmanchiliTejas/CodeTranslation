#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
using namespace std;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define rg register
#define il inline
#define lch(x) ((x)<<1)
#define rch(x) ((x)<<1^1)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep0(i,n) for(register int i=0;i<(n);++i)
#define per0(i,n) for(register int i=(n)-1;i>=0;--i)
#define rep(i,st,ed) for(register int i=(st);i<=(ed);++i)
#define per(i,ed,st) for(register int i=(ed);i>=(st);--i)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> il T qmin(const T &a,const T &b){return a<b?a:b;}
template<typename T> il T qmax(const T &a,const T &b){return a>b?a:b;}
template<typename T> il void getmin(T &a,const T &b){if(a>b) a=b;}
template<typename T> il void getmax(T &a,const T &b){if(a<b) a=b;}
il void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=(int)1e9+7;
const ll linf=(ll)1e17+7;
const int N=4e4+7;
const int mod=(476<<21)+1,g=3;

il ll qpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}

ll wn[N],fac[N],inv[N];

il void dft(ll *a,int n){
	for(int i=0,j=0;i<n;++i){
		if(j>i) swap(a[i],a[j]);
		for(int k=n>>1;(j^=k)<k;k>>=1); 
	}
	for(int i=2,id=1;i<=n;i<<=1,++id){
		ll w=wn[id];
		int len=i>>1;
		for(int j=0;j<n;j+=i){
			ll cur=1;
			for(int k=j;k<j+len;++k){
				ll u=a[k],v=a[k+len]*cur%mod;
				a[k]=(u+v)%mod,a[k+len]=(u-v+mod)%mod;
				cur=cur*w%mod; 
			}
		} 
	}
}

char s[N],t[N];
int n,m,e,len;
ll ans[N],a[N];

int main(){
	rep0(i,22) wn[i]=qpow(g,(mod-1)>>i);
	fac[0]=1;
	rep(i,1,N-1) fac[i]=fac[i-1]*i%mod;
	scanf("%s%s",s,t),n=strlen(s);
	rep0(i,n){
		if(s[i]=='1'&&t[i]=='1') ++m;
		if(s[i]=='1'&&t[i]=='0') ++e;
	} 
	for(len=2;len<=2*m;len<<=1);
	rep(i,0,m) a[i]=qpow(fac[i+1],mod-2);
	ans[0]=1;
	ll inv=qpow(len,mod-2),pw=e;
	while(pw){
		dft(a,len);
		if(pw&1){
			dft(ans,len);
			rep0(i,len) ans[i]=ans[i]*a[i]%mod;
			dft(ans,len);
			reverse(ans+1,ans+len);
			rep0(i,len) ans[i]=ans[i]*(i>m?0:inv)%mod;
		}
		rep0(i,len) a[i]=a[i]*a[i];
		dft(a,len);
		reverse(a+1,a+len); 
		rep0(i,len) a[i]=a[i]*(i>m?0:inv)%mod;
		pw>>=1;
	}
	ll sum=0;
	rep(i,0,m) sum=(sum+ans[i])%mod;
	printf("%lld\n",sum*fac[e]%mod*fac[m]%mod*fac[e+m]%mod);
	return 0;
}
