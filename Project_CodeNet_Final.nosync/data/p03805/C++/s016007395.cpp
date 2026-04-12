#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const double PI = acos(-1);

vector<vector<int>> G;
vector<bool> visited;
ll ans = 0;

void dfs(int cur) {
	bool f = true;
	for (int i = 0; i < sz(visited); i++) {
		if (!visited[i] && i != cur) {
			f = false;
		}
	}
	if (f) {
		ans++;
		return;
	}

	visited[cur] = true;
	for (auto g : G[cur]) {
		if (!visited[g]) {
			dfs(g);
		}
	}
	visited[cur] = false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n, m;
	cin >> n >> m;

	G.resize(n);

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	visited.resize(n, false);

	dfs(0);

	out(ans);

	return 0;
}