#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <numeric> //lcm
#include <iomanip> //double精度 setprecision

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep1(i,n) for(int i = (n); i >= 1; --i)
#define REP(i,n,m) for(int i = (n); i < (m); ++i)
#define all(vec) (vec).begin(),(vec).end()

#define debug(vec) for(auto v : vec) cerr << v << " "; cerr << endl;
#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << v << " "; cerr << endl; } 
#define debugP(vec) for(auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl;
#define debug2DP(vec2D) for(auto vec : vec2D) { for (auto v : vec) cerr << "(" << v.first << "," << v.second << ") "; cerr << endl; } 

typedef long long ll;

constexpr ll INF = 1000000000; //10^10
//const ll MOD = 998244353;
constexpr ll MOD = 1000000007;

template<class T> inline bool chmax(T& a, T b) { if (a <= b) { a = b; return true; } else return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }

void dfs(vector<vector<ll>>& graph,vector<bool> done, int v, ll& ans) {
  int n = done.size();
	bool ok = true;
	done[v] = true;
	rep(i, n) ok &= done[i];

	if (ok) ans++;
	else {
		for (int w : graph[v]) {
			if (!done[w]) dfs(graph, done, w, ans);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, m; cin >> n >> m;
	vector<vector<ll>> graph(n, vector<ll>());
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	ll ans = 0;

	vector<bool> done(n,false);

	dfs(graph, done, 0, ans);
	cout << ans << endl;
}