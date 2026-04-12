#include <bits/stdc++.h>
#include <unordered_map>

const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

#define MAX_V 10
struct edge {
	int to;
	int cost;
};
vector<edge> G[MAX_V];
int d[MAX_V];

ll n, m;
ll ans = 0;

void dfs(ll now, ll bit) {
	bit |= 1LL << (now - 1LL);

	if (bit == (1LL << n) - 1LL) {
		ans++;
	}

	for (auto e : G[now]) {
		if ((bit >> (e.to - 1) & 1) == 0) {
			dfs(e.to, bit);
		}
	}
}

void solve_abc_c() {
	//ll n, m;
	ll a, b;
	//ll ans = 0;
	//double ans = 0;
	
	cin >> n >> m;

	edge e;
	rep(i, m) {
		cin >> a >> b;
		e.cost = 1;
		e.to = a;
		G[b].push_back(e);
		e.to = b;
		G[a].push_back(e);
	}

	dfs(1, 0);

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_c();

	return 0;
}
