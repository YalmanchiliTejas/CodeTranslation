#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,ncnt;
ll d[105],f[105],a[105];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int solve(int l,int r,int x){
	int rt=++ncnt;
	if(l==r){
		d[rt]=0,f[rt]=qpow(2,a[l]-x);
		return rt;
	}
	ll mina=1<<30;
	for(int i=l;i<=r;i++) chkmin(mina,a[i]);
	int lst=l-1;
	f[rt]=qpow(2,mina-x),d[rt]=1;
	for(int i=l;i<=r;i++){
		if(a[i]==mina){
			d[rt]=mod(d[rt]<<1);
			if(lst+1==i){
				lst=i;
				continue;
			}
			int tmp=solve(lst+1,i-1,mina);
			f[rt]=f[rt]*f[tmp]%cys;
			d[rt]=d[rt]*(d[tmp]+(f[tmp]<<1))%cys;
			lst=i;
		}
	}
	if(lst!=r){
		int tmp=solve(lst+1,r,mina);
		f[rt]=f[rt]*f[tmp]%cys;
		d[rt]=d[rt]*(d[tmp]+(f[tmp]<<1))%cys;
	}
	d[rt]=mod(d[rt]+cys-f[rt]*qpow((cys+1)/2,mina-x-1)%cys);
	return rt;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int tmp=solve(1,n,0);
	printf("%lld\n",mod(d[tmp]+f[tmp]));
	return 0;
}