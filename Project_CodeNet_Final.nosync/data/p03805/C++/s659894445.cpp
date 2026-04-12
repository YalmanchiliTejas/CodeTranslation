#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/16  Problem: nagoya_19_04  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N, M;

LL ans = 0LL;
VVI G;


int g[10][10] = {};


int dfs(int s, int N, vector<bool>used) {
	bool flag = true;
	FOR(i, 0, N) {
		if (used[i] == false) {
			flag = false;
		}
	}
	if (flag)return 1;
	int sum = 0;
	FOR(i, 0, N) {
		if (g[s][i] == 0)continue;
		if (used[i])continue;
		used[i] = true;
		sum += dfs(i, N, used);
		used[i] = false;
	}
	return sum;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	FOR(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	vector<bool> used(n);
	used[0] = true;
	cout << dfs(0, n, used) << endl;

	return 0;
}