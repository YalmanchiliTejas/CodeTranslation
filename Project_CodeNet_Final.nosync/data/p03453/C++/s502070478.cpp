/****** BISMILLAH HIR RAHMANIR RAHIM ******/

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef vector<pair<int,int> > vpii;

// Order Statistic Tree

/* Special functions: 

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

// typedef tree<
// int,
// null_type,
// less<int>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define MAX 200002
#define debug cout<<"A"<<"\n"
#define prnt(a) cout<<a<<"\n"
#define mod 1000000007LL
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lc ((node)<<1)
#define rc ((node)<<1|1)
#define VecPrnt(v) FOR(J,0,v.size()) cout<<v[J]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl
#define ClearQ(x); while(!x.empty()) x.pop()
#define EPS 1e-9
#define ArrPrint(a,st,en) for(int J=st; J<=en; J++) cout<<a[J]<<" "; cout<<endl;

/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

inline ll power(ll a, ll b)
{
	ll multiply=1;
	FOR(i,0,b)
	{
		multiply*=a;
	}
	return multiply;
}

/****** END OF HEADER ******/

bool visited[MAX];
int n, m, s, t;
vpii graph[MAX], dags[MAX], dagt[MAX];
ll distt[MAX], dists[MAX], dps[MAX], dpt[MAX];
vector<pair<pii,ll>> edges;
vi revs[MAX], revt[MAX];

void dijkstra(int src, bool fl)
{
	priority_queue<pii> pq;
	vector<ll> d(n+1,1e16);
	d[src]=0;
	pq.push({-d[src],src});

	while(!pq.empty())
	{
		auto t=pq.top();
		pq.pop();

		int u=t.second;

		for(auto it: graph[u])
		{
			int v=it.first;

			if(d[u]+it.second<d[v])
			{
				d[v]=d[u]+it.second;
				pq.push({-d[v],v});
			}
		}
	}

	FOR(i,1,n+1)
	{
		int u=i;
		for(auto it: graph[u])
		{
			int v=it.first;

			if(d[v]==d[u]+it.second)
			{
				if(!fl) dags[u].pb({v,it.second}), revs[u].pb(v);
				else dagt[u].pb({v,it.second}), revt[u].pb(v);
			}
		}
	}

	if(!fl) FOR(i,1,n+1) dists[i]=d[i];
	if(fl) FOR(i,1,n+1) distt[i]=d[i];
}

vi tops;

void dfss(int u)
{
	visited[u]=true;

	for(auto v: revs[u])
	{
		if(!visited[v])
		{
			dfss(v);
		}
	}

	tops.pb(u);
}

void dfst(int u)
{
	visited[u]=true;

	for(auto v: revt[u])
	{
		if(!visited[v])
		{
			dfst(v);
		}
	}

	tops.pb(u);
}

void calcdps(int src, vi &order)
{
	FOR(i,0,order.size())
	{
		int u=order[i];
		for(auto it: dags[u])
		{
			int v=it.first;
			// cout<<u<<" "<<v<<endl;
			dps[v]+=dps[u];
			dps[v]%=mod;
		}
	}
}

void calcdpt(int src, vi &order)
{
	FOR(i,0,order.size())
	{
		int u=order[i];
		for(auto it: dagt[u])
		{
			int v=it.first;
			// cout<<u<<" "<<v<<endl;
			dpt[v]+=dpt[u];
			dpt[v]%=mod;
		}
	}
}

void calc(int src, bool fl)
{
	ms(visited,false);
	tops.clear();

	if(fl) dfss(src);
	else dfst(src);

	// VecPrnt(tops);
	REVERSE(tops);

	if(fl) calcdps(src,tops);
	else calcdpt(src,tops);
}

int u, v, d;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL); cout.tie(NULL);
    // freopen("in.txt","r",stdin);

    int test, cases=1;

    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);

    FOR(i,0,m)
    {
    	scanf("%d%d%d", &u, &v, &d);
    	graph[u].pb({v,d});
    	graph[v].pb({u,d});
    	edges.pb({{u,v},d});
    }

    dijkstra(s,0);
    dijkstra(t,1);

    dps[s]=1; calc(s,1);
    dpt[t]=1; calc(t,0);

    // cout<<dists[t]<<" "<<distt[s]<<endl;

    ll ans=dps[t]*dpt[s];
    ans%=mod;

    // prnt(ans);

    ll dt=dists[t];

    FOR(i,1,n+1)
    {
    	if(dists[i]==distt[i] && dists[i]+distt[i]==dt)
    	{
    		ll temp=(dps[i]*dpt[i])%mod;
    		temp=(temp*temp)%mod;    		

    		ans-=temp; ans%=mod;
    		if(ans<0) ans+=mod;
    	}
    }

    // prnt(ans);
    // prnt(dt);

    FOR(i,1,n+1)
    {
		for(auto it: dags[i])
		{
			int u=i;
			int v=it.first;

			// cout<<u<<": "<<dists[u]<<endl;
			// cout<<v<<": "<<distt[v]<<endl;
			// cout<<"dist: "<<dists[u]+distt[v]+it.second<<" "<<dt/2<<endl;

			if(dists[u]+distt[v]+it.second==dt && 2*dists[u]<dt && 2*distt[v]<dt)
			{
				// debug;
				ll temp=(dps[u]*dpt[v])%mod;
				temp=(temp*temp)%mod;

				ans-=temp; ans%=mod;
				if(ans<0) ans+=mod;
			}
		}
    }

    prnt(ans);

    return 0;
}

