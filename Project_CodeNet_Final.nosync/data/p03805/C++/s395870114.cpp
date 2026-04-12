/* */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())
string to_string (string s) { return "\"" + s + "\""; }
template<typename T> string to_string (vector<T>);
template<typename U, typename V> string to_string (pair<U, V> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename T> string to_string (vector<T> v) { string r = "["; for (int i = 0; i < (int)v.size() - 1; i++) r += to_string(v[i]) + ", ";
	if (!v.empty()) r += to_string(v.back()); return r + "]"; }

const int N = 10;
int n, m, ans;
vector<vi> adj;

void solve(int u, int V) {
	if (V == (1 << n) - 1) { ans++; return; }
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (V & (1 << v)) continue;
		solve(v, V | (1 << v));
	}
}

int main () { 
#ifdef XVENOM
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int x, y;
	scanf("%d%d", &n, &m);
	adj.assign(n, vi(0));
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	ans = 0;
	solve(0, 1 << 0);
	printf("%d\n", ans);
}