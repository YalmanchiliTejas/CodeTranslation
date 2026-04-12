#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define uint unsigned int
#define MOD 1000000007
#define MAXN 200005
#define MAXH 4
#define MAXM 100
#define INF 1LL << 60
#define ll long long
#define ull unsigned long long
#define RNG mt19937
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;
const int N = 100005;
int n,m;
vector<pll> g[N];

inline ll mul(ll x, ll y){
	return x * y % MOD;
}

inline ll add(ll x, ll y){
	ll res = x + y;
	if(res >= MOD)res-=MOD;
	return res;
}

inline ll sub(ll x, ll y){
	ll res = x + MOD - y;
	if(res >= MOD)res -= MOD;
	return res;
}

inline ll sqr(ll x){
	return mul(x,x);
}

vector<pll> dij(int s){
	vector<pll> d(n, {INF,0});
	priority_queue<pair<pll,ll>, vector<pair<pll,ll>>, greater<pair<pll,ll>>> pq;
	pq.push({{0,s},-1});
	while(pq.size()){
		int cur = pq.top().F.S;
		ll dist = pq.top().F.F;
		ll pri = pq.top().S;
		pq.pop();
		if(d[cur].F == INF){
			d[cur].F = dist;
			d[cur].S = (pri == -1?1:d[pri].S);
			for(pll a:g[cur]){
				if(dist + a.S <= d[a.F].F){
					pq.push({{dist + a.S , a.F}, cur});
				}
			}
		}
		else if(dist == d[cur].F){
			d[cur].S = add(d[cur].S, d[pri].S);	
		}
	}
	return d;
}

int main(){
	fast_io();
	cin >> n >> m;
	int s,t;
	cin >> s >> t;
	--s;--t;
	cu(i,0,m){
		ll x,y,w;
		cin >> x >> y >> w;
		--x;--y;
		g[x].pb({y,w});
		g[y].pb({x,w});
	}
	vector<pll> sd = dij(s);
	vector<pll> td = dij(t);
	ll ans = sqr(sd[t].S);
	ll dist = sd[t].F;
	cu(i,0,n){
		if(sd[i].F * 2 == dist && sd[i].F == td[i].F){ // meet at the vertex
			ans = sub(ans, sqr(mul(sd[i].S, td[i].S)));	
		}
		for(pll a:g[i]){
			if(sd[i].F + a.S + td[a.F].F == dist && sd[i].F * 2 < dist && td[a.F].F * 2 < dist){ // meet in the edge (not at the vertex)
				ans = sub(ans, sqr(mul(sd[i].S, td[a.F].S)));
			}
		}
	}
	cout << ans << '\n';
}
