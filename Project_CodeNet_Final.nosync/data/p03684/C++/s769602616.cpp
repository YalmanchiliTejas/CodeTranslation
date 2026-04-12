#include <bits/stdc++.h>
#define int LL
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,b,a) for(int i=b;i>=a;i--)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forenska(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define GREATER(x) x,vector<x>,greater<x>
#define randIn(L,R) (((LL)rand()*rand())%(R-L)+L)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef vector<int> vec;
typedef vector<LL> vecL;
typedef vector<pii> vecP;
typedef vector<pLL> vecPL;
typedef vector<string> vecS;
typedef vector<vec> mat;
const long double PI=3.14159265358979323846264338327950;
const LL INFLL=0x3f3f3f3f3f3f3f3f;
const int INF=0x3f3f3f3f;
const long double EPS=1e-10;
int read()
{
    int x=0;
    char ch=' ';
    bool flag=false;
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')flag=true;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return flag?-x:x;
}
int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
struct point
{
	int num;
	int x;
	int y;
	point(){}
	point(int _x,int _y,int _num)
	{
		x=_x;
		y=_y;
		num=_num;
	}
};
bool compx(point A,point B)
{
	return A.x<B.x || A.x==B.x && A.y<B.y;
}
bool compy(point A,point B)
{
	return A.y<B.y || A.y==B.y && A.x<B.x;
}
const int MAX_N=100005;
vector <point> a;
int n;
vector <pair<int,pii> > g;
void build(int i,int j)
{
	int cost=min(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y));
	g.pb(mp(cost,mp(a[i].num,a[j].num)));
}
int fa[MAX_N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
	fa[find(x)]=find(y);
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
signed main()
{
	cin>>n;
	a.resize(n);
	rep(i,0,n)
	{
		int x=read(),y=read();
		a[i]=point(x,y,i);
	}
	sort(all(a),compx);
	rep(i,1,a.size())
	{
		build(i,i-1);
	}
	sort(all(a),compy);
	rep(i,1,a.size())
	{
		build(i,i-1);
	}
	sort(all(g));
	rep(i,0,n)fa[i]=i;
	int ans=0;
	rep(i,0,g.size())
	{
		int u=g[i].se.fi,v=g[i].se.se;
		if(!same(u,v))
		{
			unite(u,v);
			ans+=g[i].fi;
		}
	}
	cout<<ans<<endl;
	return 0;
}


