#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>
#include<utility>
#include<numeric>

#define PB push_back
#define all(a)  (a).begin(),(a).end()
#define ALL(v) begin(v), end(v)
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define V vector<int>
#define VV vector<V>
#define VVV vector<VV>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int inf = (int)1e9;
const ll INF = (ll)1e18;
const ll MOD{ (ll)1e9 + 7 };
const long double EPS = 1e-10;

int n, m;
vector<int> g[100];
bool visited[100];

int dfs(int from, int cnt) {
	if (cnt >= n - 1) return 1;
	visited[from] = true;
	int ret = 0;
	for (int to : g[from]) {
		if (visited[to]) continue;
		ret += dfs(to, cnt + 1);
	}
	visited[from] = false;
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout << dfs(0, 0) << endl;
	return 0;
}