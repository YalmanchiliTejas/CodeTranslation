#pragma region
#include <bits/stdc++.h>
using namespace std;
#define ri register int
#define il inline
#define LL long long
#define uint unsigned int
#define ull unsigned long long
#define solid const auto &
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
#define fi first
#define se second
#define gm int mid((l+r)/2)
#define space putchar(' ')
#define enter putchar('\n')
#define rd() ({ri t;in(t);t;})
#define Size(x) ((int)x.size())
#define mem(x,y) memset(x,y,sizeof(x))
template<class T>il void in(T &x)
{
	x=0; char c=getchar(); bool f=0;
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=x*10+(c^'0'),c=getchar();
	f?x=-x:0;
}
template<class T>il void out(T x,const char c='\n')
{
	static short st[30]; short m=0;
	if(x<0) {if(x==-2147483648) {printf("-2147483648"); return;} putchar('-'),x=-x;}
	do st[++m]=x%10,x/=10; while(x);
	while(m) putchar(st[m--]|'0');
	putchar(c);
}
template<class T,class ...Args>il void in(T &x,Args &...args) {in(x); in(args...);}
template<class T,class ...Args>il void out(const T &x,const Args &...args) {out(x,' '); out(args...);}
template<class T>il void prt(T a[],int n) {for(ri i=0; i<n; ++i) out(a[i],' '); enter;}
template<class T>il void clr(T a[],int n) {memset(a,0,sizeof(T)*n);}
template<class T>il void clr(T *a,T *b) {memset(a,0,sizeof(T)*(b-a));}
template<class T>il bool ckmax(T &a,const T &b) {return a<b?a=b,1:0;}
template<class T>il bool ckmin(T &a,const T &b) {return a>b?a=b,1:0;}
namespace MOD_CALC
{
const int md=998244353,inv2=(md+1)/2;
il int add(const int a,const int b) {return a+b>=md?a+b-md:a+b;}
il int sub(const int a,const int b) {return a-b<0?a-b+md:a-b;}
il int mul(const int a,const int b) {return (LL)a*b%md;}
il void inc(int &a,const int b) {(a+=b)>=md?a-=md:0;}
il void dec(int &a,const int b) {(a-=b)<0?a+=md:0;}
il int qpow(int a,int b) {int r=1; for(; b; b>>=1,a=mul(a,a)) if(b&1) r=mul(r,a); return r;}
il int mdinv(const int a) {return qpow(a,md-2);}
template<class ...Args>il int add(const int a,const int b,const Args &...args) {return add(add(a,b),args...);}
template<class ...Args>il int mul(const int a,const int b,const Args &...args) {return mul(mul(a,b),args...);}
} using namespace MOD_CALC;
namespace i207M
{
#pragma endregion
#define N 200005
const int inf=1e9;
int n;
struct Node
{
	int a,b;
} p[N];
bool cmp(const Node &x,const Node &y)
{
	return x.a<y.a;
}
multiset<int>s;
il LL calc()
{
	return *s.rbegin()-*s.begin();
}
signed main()
{
#ifdef M207
	freopen("in.in","r",stdin);
	// freopen("ot.out","w",stdout);
#endif
	in(n);
	int rmax=0,rmin=inf,bmax=0,bmin=inf;
	for(ri i=1; i<=n; ++i)
	{
		in(p[i].a,p[i].b);
		if(p[i].a>p[i].b) swap(p[i].a,p[i].b);
		ckmax(rmax,p[i].b);
		ckmin(rmin,p[i].b);
		ckmax(bmax,p[i].a);
		ckmin(bmin,p[i].a);
	}
	LL ans1=(LL)(rmax-rmin)*(bmax-bmin);
	sort(p+1,p+1+n,cmp);
	for(ri i=1; i<=n; ++i) s.insert(p[i].a);
	LL ans2=calc();
	for(ri i=1; i<=n; ++i)
	{
		s.erase(s.find(p[i].a));
		s.insert(p[i].b);
		ckmin(ans2,calc());
	}
	ans2*=rmax-bmin;
	out(min(ans1,ans2));
	return 0;
}
#pragma region
}
signed main()
{
	i207M::main();
	return 0;
}
#pragma endregion
