#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<pair<int,int> > vii;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,pair<int,int> > iii;
#define PI 3.141592653589793
#define mod (ll)(1000*1000*1000+7)
//# define N 300005
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=((ans%m)*(a%m))%m; b/=2; a=((a%m)*(a%m))%m; } return ans%m; }
# define INF (ll)1e18
# define LG 20  
typedef pair<int,pair<int,int> > pii;
# define INF1 (int)1e9+2v
# define maxn 100006

ll sz[maxn];
int par[maxn];
int x[maxn],y[maxn];

void init()
{
	for(int i=0;i<maxn;i++)
	{
		par[i]=i;
		sz[i]=1;
	} 
}

int root(int a)
{
	while(a!=par[a])
	{
		a=par[a];
	}
	return a;
}


bool issame(int a,int b)
{
	a=root(a);b=root(b);
	if(a==b)
		 return true;
	return false;
	
}

void union1(int a,int b)
{
	a=root(a);
	b=root(b);
  if(sz[a]<sz[b])
		swap(a,b);
	sz[a]+=sz[b];
	par[b]=a;
}

int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];

    init();
    vector<pair<ll,int> >xc,yc;

    for(int i=0;i<n;i++)
    {
    	xc.pb(mp(x[i],i));
    	yc.pb(mp(y[i],i));
    }
    sort(xc.begin(),xc.end());
    sort(yc.begin(),yc.end());

    vector<pair<ll,pair<int,int> > >ed;

    for(int i=0;i<xc.size()-1;i++)
    {
    	int f=xc[i].ss;
    	int s=xc[i+1].ss;
    	int d=xc[i].ff-xc[i+1].ff;
    	ed.pb(mp(abs(d),mp(f,s)));
    	f=yc[i].ss;s=yc[i+1].ss;d=abs(yc[i].ff-yc[i+1].ff);
    	ed.pb(mp(d,mp(f,s)));
    }

    sort(ed.begin(),ed.end());
    
    ll ans=0;
    for(int i=0;i<ed.size();i++)
    {
    	int from=ed[i].ss.ff;
    	int to=ed[i].ss.ss;
    	//trace4(from,to,ed[i].ff,issame(from,to));
    	if(!issame(from,to))
    	{
    		union1(from,to);
    		ans+=ed[i].ff;
    		//trace1(issame(from,to));
    	}
    }

    cout << ans;
}