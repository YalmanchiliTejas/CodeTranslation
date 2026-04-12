#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct point
{
	long long name; long long dist;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
ll const MOD = 1e9 + 7;

ll const MAX = 200005;
ll dist[MAX] = {};
ll n, m;
struct edge {
	ll to; ll dist;
};

ll const INF = 1e18;
priority_queue<point> pq;
vector<edge> G[MAX];
vector<edge> S[MAX];
vector<edge> T[MAX];

ll dp_s[MAX] = {};
ll dp_t[MAX] = {};

bool ord(ll x, ll y) {
	return dist[x] < dist[y];
}

ll num[MAX];

ll dijkstra(ll start, ll goal) {
	REP(i, 1, n) {
		dist[i] = INF;
	}
	ll cnt = n;
	pq.push({ start,0 });
	while (!pq.empty() && cnt > 0) {
		point curp = pq.top();
		pq.pop();
		ll cur = curp.name; ll curd = curp.dist;
		if (dist[cur] == INF) {
			cnt--;
			dist[cur] = curd;
			REP(i, 0, SIZE(G[cur]) - 1) {
				edge next_e = G[cur][i];
				if (dist[next_e.to] != INF) continue;
				pq.push({ next_e.to, curd + next_e.dist });
			}
		}
	}
	return dist[goal];
}


void filldp(ll dp[], vector<edge> X[], ll start) {
	dp[start] = 1;
	REP(i, 1, n) {
		ll cur = num[i];
		REP(j, 0, SIZE(X[cur]) - 1) {
			ll next = X[cur][j].to;
			dp[next] = (dp[next] + dp[cur]) % MOD;
		}
	}
}

int main() {
	cin >> n >> m;
	ll s, t;
	cin >> s >> t;
	REP(i, 1, m) {
		ll u, v, d;
		cin >> u >> v >> d;
		G[u].push_back({ v,d*2 });
		G[v].push_back({ u,d*2 });
	}
	ll d;
	d = dijkstra(s,t);
	d /= 2;
	REP(i, 1, n) {
		num[i] = i;
	}
	SORT_O(num, n, ord);
	REP(i, 1, n) {
		REP(j, 0, SIZE(G[i]) - 1) {
			ll f = i;
			ll to = G[i][j].to;
			ll dis = G[i][j].dist;
			if (dis + dist[f] == dist[to]) {
				S[f].push_back({ to,dis });
				T[to].push_back({ f,dis });
			}
		}
	}


	filldp(dp_s, S, s);
	reverse(num + 1, num + 1 + n);
	filldp(dp_t, T, t);
	ll ans = 0;
	REP(i, 1, n) {
		if (dist[i] == d) {
			
			ll cur = dp_s[i] * dp_t[i] % MOD;
			ans = (ans + cur * cur%MOD) % MOD;
			//cout << i << " _ " << cur << endl;
		}
		else {
			REP(j, 0, SIZE(S[i]) - 1) {
				ll next = S[i][j].to;
				if (dist[i] < d && dist[next] > d) {
					ll cur = dp_s[i] * dp_t[next] % MOD;
					ans = (ans + cur * cur % MOD) % MOD;
					//cout << i << " " << next << " ! " << cur << endl;
				}
			}
		}
	}
	/*
	REP(i, 1, n) {
		cout << dist[i] << " ";
	}
	cout << endl;
	REP(i, 1, n) {
		cout << dp_s[i] << " ";
	}cout << endl;
	REP(i, 1, n) {
		cout << dp_t[i] << " ";
	}
	cout << endl;
	*/
	cout << (dp_s[t]*dp_s[t]%MOD-ans+MOD)%MOD << endl;
}