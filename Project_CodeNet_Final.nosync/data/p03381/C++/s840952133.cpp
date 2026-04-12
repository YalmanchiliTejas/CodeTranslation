#include<bits/stdc++.h>
#define de(x) cout<<#x<<"="<<x<<endl;
#define dd(x) cout<<#x<<"="<<x<<" ";
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repd(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b,t) for(int i=a;i<(b);i+=t)
#define ll long long
#define mt(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define pdd pair<double,double>
#define pdi pair<double,int>
#define mp(u,v) make_pair(u,v)
#define sz(a) (int)a.size()
#define ull unsigned long long
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define qc std::ios::sync_with_stdio(false)
#define db double
#define lson (k<<1)
#define rson (k<<1)+1
const int mod = 1e9+7;
const int maxn = 2e5+6;
const double eps = 1e-6;
using namespace std;
bool eq(const db &a, const db &b) { return fabs(a - b) < eps; }
bool ls(const db &a, const db &b) { return a + eps < b; }
bool le(const db &a, const db &b) { return eq(a, b) || ls(a, b); }
ll gcd(ll a,ll b) { return a==0?b:gcd(b%a,a); };
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll kpow(ll a,ll b) {ll res=1; if(b<0) return 1; for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll read(){
    ll x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//inv[1]=1;
//for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
struct P{
	int x,id,b;
}a[maxn];
bool cmp1(P t,P s){
	return t.x<s.x;
}
bool cmp2(P t,P s){
	return t.id<s.id;
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1,cmp1);
	rep(i,1,n+1){
		int m = n/2 + 1;
		if(i<m) a[i].b = a[m].x;
		else a[i].b = a[m-1].x;
	}
	sort(a+1,a+n+1,cmp2);
	rep(i,1,n+1) printf("%d\n",a[i].b);
	return 0;
}
