#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
typedef long long ll;
void read(ll &x)
{
	scanf("%lld",&x);
}
void print(ll x)
{
	printf("%lld ",x);
}
void println(double x)
{
	printf("%.9f\n",x);
}

#define F first
#define S second
ll n;
ll p[200200];
vector<pair<ll, pair<ll, ll > > > edges;

inline int get(int v)
{
	if(p[v] == v) return v;
	return p[v] = get(p[v]);
}
pair<ll, pair<ll, ll > > a[200200];

inline bool cmp(pair<ll, pair<ll, ll> > a, pair<ll, pair<ll, ll > > b)
{
	if(a.S.F != b.S.F)
		return a.S.F < b.S.F;
	return a.F < b.F;
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		read(a[i].F);
		read(a[i].S.F);
		a[i].S.S = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = max(i - 4ll, 1ll); j <= min(n, i + 4ll); ++j)
		{
			ll dist = min(abs(a[i].F - a[j].F), abs(a[i].S.F - a[j].S.F));
			edges.pb(mp(dist, mp(a[i].S.S, a[j].S.S)));
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = max(i - 4ll, 1ll); j <= min(n, i + 4ll); ++j)
		{
			ll dist = min(abs(a[i].F - a[j].F), abs(a[i].S.F - a[j].S.F));
			edges.pb(mp(dist, mp(a[i].S.S, a[j].S.S)));
		}
	}
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	ll ans = 0;
	sort(edges.begin(), edges.end());
	for(int i = 0; i < edges.size(); ++i)
	{
		int v = edges[i].S.F, u = edges[i].S.S;
		int cost = edges[i].F;
		v = get(v);
		u = get(u);
		if(u == v) continue;
	//	cerr<<u<<' '<<v<<' '<<cost<<endl;
		p[u] = v;
		ans += cost;
	}
//	for(int i = 1; i <= n; ++i)
//		cerr<<p[i]<<' ';
//	cerr<<endl;
	cout << ans;
}