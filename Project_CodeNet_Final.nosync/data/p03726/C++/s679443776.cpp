// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 2e9;
const ll MOD = 998244353;//1e9 + 7;
 
////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int DP[2][N];
vector<int> G[N];

void DFS(int v, int p = 0) {
	for (int u : G[v]) if (u != p) DFS(u, v), DP[0][v] += max(DP[0][u], DP[1][u]);
	for (int u : G[v]) if (u != p) DP[1][v] = max(DP[1][v], DP[0][v] - max(DP[0][u], DP[1][u]) + DP[0][u] + 1);
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	DFS(1);
	int mx = max(DP[0][1], DP[1][1]);
	if (n % 2 == 0 && 2 * mx == n) cout << "Second" << endl;
	else cout << "First" << endl;

	return 0;
}
