#include <bits/stdc++.h>
using namespace std;
#define mid ((s + e) / 2)
#define makefast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define comp(x, y) (lower_bound(vec.begin(), vec.end(), make_pair(x, y)) - vec.begin())
#define lc (v * 2)
#define rc (v * 2 + 1)
long long M = 1e9 + 7;
//>>>>>>>>>>>>>>>>>>>

const int N = 1e5 + 7;

vector <int> ad[N];
int n;
int dp[N][2];

void solve(int v, int p) {
	bool allh0 = 1, one1 = 0;
	int no0 = 0, cnt0 = 0, call = 0;
	for (auto u: ad[v])
		if (u != p) {
			call++;
			solve(u, v);
			if (!dp[u][0]) {
				allh0 = 0;
				no0 = u;
			}
			else
				cnt0++;
			if (dp[u][1])
				one1 = 1;
		}
	if (allh0)
		dp[v][1] = 1;
	if (allh0 && one1)
		dp[v][0] = 1;
	if (cnt0 == call - 1 && one1 && dp[no0][1] == 1)
		dp[v][0] = 1;
}
int main() {
	makefast;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		ad[v].push_back(u);
		ad[u].push_back(v);
	}	
	solve(1, 0);
	if (dp[1][0])
		cout << "Second";
	else
		cout << "First";
	
}