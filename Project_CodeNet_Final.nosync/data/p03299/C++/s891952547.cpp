#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1555,mo=1e9+7,inv2=(mo+1)/2;
int n,a[N],cnt;ll f[N],g[N],h[N];
ll power(ll a, ll n){
	ll res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
int solve(int l, int r, int d){
	int k=++cnt,mn=2e9;rep(i,l,r)mn=min(mn,a[i]);
	Vi ch;int tot=0;rep(i,l,r)tot+=(a[i]==mn);
	rep(i,l,r)if(a[i]>mn){
		int j;for(j=i;j<=r;j++)if(a[j]<=mn)break;
		ch.pb(solve(i,j-1,mn+1));i=j-1;
	}
	h[k]=mn-d+1;rep(i,0,SZ(ch)-1)h[k]+=h[ch[i]];
	g[k]=power(2,h[k]);
	int x=power(2,tot),y=2;
	rep(i,0,SZ(ch)-1)x=1LL*x*(f[ch[i]]+g[ch[i]]*2LL)%mo,y=1LL*y*g[ch[i]]%mo;
	f[k]=(x-y+mo)%mo;
//	printf("%d %d %d:%d %d %d\n",l,r,d,f[k],g[k],h[k]);
	return k;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);int rt=solve(1,n,1);
	printf("%lld",(f[rt]+g[rt])%mo);
	return 0;
}
