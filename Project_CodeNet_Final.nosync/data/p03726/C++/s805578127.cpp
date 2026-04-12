#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N][3], n;
vector<int> gr[N];
void getAns(int v, int par = -1) {
	for (auto u : gr[v]) {
		if (u != par) {
			getAns(u, v);
			dp[v][1] += dp[u][0], dp[v][0] += dp[u][0], dp[v][0] += (dp[u][0] == dp[u][1]);
		}
	}
	dp[v][0] = min(dp[v][0], dp[v][1] + 1);
//	cout << "v = " << v << " : " << dp[v][0] << " : " << dp[v][1] << endl; 
}
int main() {
	ios_base::sync_with_stdio (false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].push_back(y), gr[y].push_back(x);
	}
	getAns(0);
	if (dp[0][0] == (n + 1) / 2)
		cout << "Second";
	else
		cout << "First";
	return 0;
}