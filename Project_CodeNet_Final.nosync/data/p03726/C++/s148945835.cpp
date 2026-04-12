#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define endt '\t'
#define ends ' '
#define die(x) return cout << x << endl, 0;
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 1e9 + 7; 

////////////////////////

const int MAXN = 1e5 + 5;

int DP[MAXN][2];
vector<int> G[MAXN];

void DFS(int v, int p = 0) {
	for (int u : G[v]) if (u != p)
		DFS(u, v), DP[v][0] += max(DP[u][0], DP[u][1]);
	for (int u : G[v]) if (u != p)
		DP[v][1] = max(DP[v][1], DP[v][0] - max(DP[u][0], DP[u][1]) + DP[u][0] + 1);
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	#ifdef LOCAL
	ifstream cin("sample.in");
	#endif

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	DFS(1);
	int mx = max(DP[1][0], DP[1][1]);
	cout << (n % 2 == 0 && (mx << 1) == n ? "Second" : "First") << endl;
	
	return 0;
}