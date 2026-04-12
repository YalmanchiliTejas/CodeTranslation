//	Totally unrelated and not AT ALL stolen from hohohaha's, generic_placeholder_name's or katoriyuu's template
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;

#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define gcd __gcd
#define rep(i,s,end) for(int i = (s); i <  (end); ++i)
#define rep1(i, end) for(int i =   1; i <= (end); ++i)
#define lb lower_bound
#define ub upper_bound

#define vt vector
#define endl "\n"

#define fileopen(filename, in_type, out_type) if (fopen(filename in_type, "r")) {freopen(filename in_type, "r", stdin);freopen(filename out_type, "w", stdout);}
#define local_input(x) if (x && fopen("input.txt","r")) freopen("input.txt","r",stdin);
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define fscan(x)   scanf("%d",  &x)
#define fscandb(x) scanf("%lf", &x)
#define fscanll(x) scanf("%lld",&x)
//	Until next time, remember:
//			You are closer than you think.
//						_Dan Lok_

#define int ll
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pi 3.1415926535897932	//faster than pi = acos(-1); but sometimes doesn't work?
//	srand(chrono::steady_clock::now().time_since_epoch().count());
//	freopen("input.txt","r",stdin);

#define mn 100002
const int mod = 1e9+7;
int add(const int& a, const int& b){
	return (a+b)%mod;
}
int mul(const int& a, const int& b){
	return (a*b)%mod;
}
int sub(const int& a, const int& b){
	int res = (a-b) % mod;
	return res < 0 ? res+mod : res;
}
struct edge{
	int u,v,dist;
};
int n,m,s,t;
vpii adjlist[mn];
edge e[mn << 1];
priority_queue<pii, vpii, greater<pii> > pq;

void dij(const int& s, vi &dist, vi &c){
	dist[s] = 0, c[s] = 1, pq.push({0,s});
	
	while(!pq.empty()){
		int u = pq.top().se, d = pq.top().fi; pq.pop();
		if(dist[u] != d) continue;
		
		for(pii& i : adjlist[u]){			
			d = dist[u]+i.se;
			if(dist[i.fi] > d){
				dist[i.fi] = d, c[i.fi] = c[u];
				pq.push({d, i.fi});
			}
			else if(dist[i.fi] == d) c[i.fi] = (c[i.fi] + c[u]) % mod;
		}
	}
}

signed main()
{
	fastio;
//	fileopen("",".inp",".out");
	local_input(true);
	cin >> n >> m >> s >> t;
	vi ds(n+1, LLONG_MAX), dt(n+1, LLONG_MAX), cs(n+1,0), ct(n+1,0);
	rep(i,0,m){
		int x,y,z; cin >> x >> y >> z;
		e[i] = {x,y,z}; adjlist[x].pb({y,z}), adjlist[y].pb({x,z});
	}
	dij(s,ds,cs), dij(t,dt,ct);
	
	int ans = 0, cc;
	rep1(i,n){
		if(ds[i]+dt[i] == ds[t]
		&& (ds[i] << 1) == ds[t])
		{
			cc = mul(cs[i],ct[i]);
			ans = add(ans-mod*mod, mul(cc,cc));
		}
	}

	rep(i,0,m){
		int u = e[i].u, v = e[i].v, w = e[i].dist;
		if(ds[u] + dt[v] + w == ds[t]
		&& (ds[u] << 1) < ds[t]
		&& (dt[v] << 1) < ds[t])
		{
			cc = mul(cs[u],ct[v]);
			ans = add(ans-mod*mod, mul(cc,cc));
		}
		
		swap(u,v);
		
		if(ds[u] + dt[v] + w == ds[t]
		&& (ds[u] << 1) < ds[t]
		&& (dt[v] << 1) < ds[t])
		{
			cc = mul(cs[u],ct[v]);
			ans = add(ans-mod*mod, mul(cc,cc));
		}
	}
//	cout << ds[t] << ' ' << cs[t] << endl;
	cout << sub(mul(cs[t], ct[s]), ans) << endl;
	return 0;
}
// with the aura of Dora, AC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Why is there a one in my row of exclamation marks?
