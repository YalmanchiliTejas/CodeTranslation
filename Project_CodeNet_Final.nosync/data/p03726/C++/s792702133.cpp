#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
#include <unordered_map>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 10;

bool z = false;

bool dfs(int u, int p, vector<vector<int> >& G) {
	int x = 0;
	for (int v: G[u]) if (v != p) x += dfs(v, u, G);
	if (x == 0) return true;
	if (x == 1) return false;
	z = true;
	return false;
}

int main() {
	int N; cin >> N;
	if (N % 2) {
		cout << "First" << endl;
		return 0;
	}
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(0, -1, G);
	cout << (z ? "First" : "Second") << endl;
}
