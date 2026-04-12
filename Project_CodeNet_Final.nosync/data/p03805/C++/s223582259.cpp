#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
vector<ll> vis[10];
bool used[10];
ll ans, n, m, a, b;
void dfs(ll x, ll y) {
	if (used[y])return;
	if (x == n) {
		ans++;
		return;
	}
	used[y] = 1;
	for (int i = 0; i < vis[y].size(); i++) dfs(x + 1, vis[y][i]);
	used[y] = 0;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++)used[i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vis[a].push_back(b);
		vis[b].push_back(a);
	}
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}
