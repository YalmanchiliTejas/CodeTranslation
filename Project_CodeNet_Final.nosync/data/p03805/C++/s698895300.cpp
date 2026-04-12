#include <bits/stdc++.h>
using namespace std;

#define first  fs
#define second se
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)

using pii = pair<int, int>;
using vi = vector<int>;
using lint = long long;

const int inf = 1001001001;
const lint linf = 1001001001001001001ll;
const int mod = 1e9 + 7;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; } return a > b; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; } return a < b; }
template<typename T> inline void print(const T &x, char s = '\n') { cout << x << s; }
template<typename T> inline void print(const vector<T> &v, string s = " ") 
{ rep(i, v.size()) cout << v[i] << (i + 1 == v.size() ? "\n" : s); }
inline bool inside(int y, int x, int H, int W) { return 0 <= y && y < H && 0 <= x && x < W; }
inline lint in() { lint x; std::cin>>x; return x; }

int n, m;
vi G[10];

int dfs(int v = 0, int bit = 1) {
	if (bit == (1 << n) - 1) return 1;
	int ret = 0;

	for (int i = 0; i < G[v].size(); ++i ) {
		if ((1 << G[v][i]) & bit) continue;
		ret += dfs(G[v][i], bit + (1 << G[v][i]));
	}

	return ret;
}
	
int main() {
	cin >> n >> m;
	rep(i, m) {
		int a = in() - 1, b = in() - 1;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	cout << dfs() << endl;
}

