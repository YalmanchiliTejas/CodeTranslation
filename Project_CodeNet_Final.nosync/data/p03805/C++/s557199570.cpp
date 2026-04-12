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
#include <unordered_set>
#include <complex>
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
// typedef complex<double> C;
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<bool> > adj(N, vector<bool>(N));
	while (M--) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u][v] = adj[v][u] = true;
	}
	vector<int> p(N);
	for (int i = 0; i < N; i++) p[i] = i;
	int cnt = 0;
	do {
		bool ok = true;
		rep(i, N - 1) if (!adj[p[i]][p[i + 1]]) ok = false;
		if (ok) cnt++;
	} while (next_permutation(p.begin() + 1, p.end()));
	cout << cnt << endl;
}
