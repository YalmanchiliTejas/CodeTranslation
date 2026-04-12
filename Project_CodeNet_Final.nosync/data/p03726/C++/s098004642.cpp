#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> ad[N], kid[N];
int n;
bool dp[N][2];

void solve(int v, int p) {
	if (ad[v].size() == 1 && p != 0) {
		dp[v][0] = 1;
		dp[v][1] = 0;
		return;
	}
	int cnt0 = 0, cnt1 = 0;
	for (auto u: ad[v]) {
		if (u == p)
			continue;
		solve(u, v);
		cnt0 += dp[u][0];
		cnt1 += dp[u][1];
		kid[v].push_back(u);
	}
	if (cnt1 == kid[v].size())
		dp[v][0] = 1;
	for (auto u: kid[v]) {
		if (dp[u][0] && cnt1- dp[u][1] == kid[v].size() - 1)
			dp[v][1] = 1;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ad[x].push_back(y);
		ad[y].push_back(x);
	}
	solve(1, 0);
	if (!dp[1][1])
		cout << "First";
	else
		cout << "Second";

	return 0;
}
