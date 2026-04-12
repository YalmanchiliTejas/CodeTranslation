#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define ln '\n'
const long long MOD = 1000000007LL;
//const long long MOD = 998244353LL;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<int>> G;
bool win = false;
int dfs(int v, int pv) {
	int cnt = 0;
	for (auto nv : G[v]) {
		if (nv==pv) continue;
		if (dfs(nv,v)) cnt++;
	}
	if (cnt == 0) return 1;
	if (cnt == 1) return 0;
	if (cnt > 1) {
		win = true;
		return 0;
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	G.resize(N);
	rep(i,N-1) {
		int u,v; cin >> u >> v;
		--u; --v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	if(dfs(0,-1)) win = true;
	cout << (win ? "First" : "Second") << ln;
}
