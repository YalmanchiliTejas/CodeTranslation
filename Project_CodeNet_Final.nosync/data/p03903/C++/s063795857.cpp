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
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct edge
{
	long long from; long long to; long long cost; 
	bool operator<(const edge& rhs) const {
		return cost > rhs.cost;
	}
};

priority_queue<edge> pq;

ll const MAX = 4006;
ll dep[MAX];
ll parent_uf[MAX];
ll rk[MAX];

void init(ll n) {
	for (ll i = 1; i <= n; i++) {
		parent_uf[i] = i;
		rk[i] = 1;
	}
}

ll find(ll x) {
	if (parent_uf[x] == x) {
		return x;
	}
	parent_uf[x] = find(parent_uf[x]);
	return parent_uf[x];
}

bool same(ll x, ll y) {
	return find(x) == find(y);
}

void unite(ll x, ll y) {
	if (!same(x, y)) {
		x = parent_uf[x];
		y = parent_uf[y];
		if (rk[x] < rk[y]) {
			parent_uf[x] = y;
		}
		else {
			parent_uf[y] = x;
			if (rk[x] == rk[y]) {
				rk[x]++;
			}
		}
	}
}

ll n, m, q;
vector<edge> G[MAX];

ll make_tree() {
	ll cnt = n - 1;	
	ll ttl = 0;

	while (cnt > 0) {
		edge cur = pq.top();
		pq.pop();
		ll cf = cur.from; ll ct = cur.to; ll cc = cur.cost;
		if (!same(cf, ct)) {
			unite(cf, ct);
			ttl += cur.cost;
			G[cf].push_back({ cf,ct,cc });
			G[ct].push_back({ ct,cf,cc });
			cnt--;
		}
	}
	return ttl;
}

ll parent[MAX];
ll costing[MAX];

void dfs() {
	parent[1] = 1;
	stack<ll> st;
	st.push(1);
	dep[1] = 0;
	while (!st.empty()) {
		ll cur = st.top();
		st.pop();
		for (ll i = 0; i < SIZE(G[cur]); i++) {
			
			ll next = G[cur][i].to;
			if (next == parent[cur]) {
				continue;
			}
			//cout << cur << " " << next << endl;
			parent[next] = cur;
			dep[next] = dep[cur] + 1;
			costing[next] = G[cur][i].cost;
			//cout << costing[next] << endl;
			st.push(next);
		}
	}
}

ll dp[MAX][MAX] = {};

ll query(ll s, ll t) {
	if (s == t) {
		return 0;
	}	
	if (dep[s] < dep[t]) {
		swap(s, t);
	}

	if (dp[s][t] != 0) {
		return dp[s][t];
	}
	//cout << v << " ?" << endl;
	dp[s][t] = max(costing[s],query(parent[s], t));
	return dp[s][t];
}

int main() {
	cin >> n >> m;
	init(n);
	REP(i, 1, m) {
		ll a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}
	ll ttl = make_tree();
	dfs();
	cin >> q;
	REP(i, 1, q) {
		ll s, t;
		cin >> s >> t;
		cout << ttl - query(s, t) << endl;
	}
}