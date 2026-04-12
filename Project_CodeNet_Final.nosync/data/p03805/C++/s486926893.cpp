#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> P;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;
struct Edge {
	ll u;
	ll v;
	ll cost;
};
using Graph = vector<vector<Edge>>;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
/***** define constant start *******/
const ll MOD = 1000000007;
const double PI = 2.0 * asin(1.0);
const ll INF = 1L<<60;
string abc = "abcdefghijklmnopqrstuvwxyz";
string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll MAX = 10000000;
/****** define constant end ********/
/****** define variable start ******/
ll n, m;
vl a, b;
vll G;
ll ans = 0;
/******* define variable end *******/
// 深さ優先探索
vector<bool> seen;
void dfs(const vll &G, ll v, ll count) {
	if(seen[v]) return;
	count++;
	if(count == n){
		ans++;
		return;
	}
    seen[v] = true;
    for (auto next_v : G[v]) {
        dfs(G, next_v, count);
    }
	seen[v] = false;
	return;
}
int solve() {
	cin >> n >> m;
	seen.resize(n);
	a.resize(m);
	b.resize(m);
	G.resize(n);
	REP(i, m){
		cin >> a[i] >> b[i];
		G[a[i]-1].push_back(b[i]-1);
		G[b[i]-1].push_back(a[i]-1);
	}
	dfs(G, 0, 0);
	cout << ans << endl;
	return 0;
}

int main() {
	//clock_t start = clock();
	cout << std::fixed << std::setprecision(10);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int end_solve = solve();
	/*
	clock_t end = clock();
	const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC *
	1000.0; printf("time %lf[ms]\n", time);
	*/

	return end_solve;
}
