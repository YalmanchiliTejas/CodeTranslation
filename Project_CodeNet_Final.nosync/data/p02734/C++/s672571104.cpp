#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int dp[3001][3001], pre[3001][3001], a[3001];

int mul(int a, int b) { return 1LL * a * b % mod; }
void add_self(int& a, int b) { a += b; if(a >= mod) a -= mod; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for(int i = 0; i < n; i++) {
		pre[i][a[i]] = dp[i][a[i]] = i+1;
	}

	for(int w = 1; w <= s; w++) {
		for(int i = 1; i < n; i++) {
			add_self(pre[i][w], pre[i-1][w]);
		}
	}

	for(int w = 1; w <= s; w++) {
		for(int i = 0; i < n; i++) {
			if(w <= a[i] || i == 0) continue;
			add_self(dp[i][w], pre[i-1][w-a[i]]);
	//		for(int j = 0; j < i; j++) {
	//			add_self(dp[i][w], dp[j][w-a[i]]);
	//		}
		}
		for(int i = 0; i < n; i++) {
			pre[i][w] = i > 0 ? pre[i-1][w] : 0;
			add_self(pre[i][w], dp[i][w]);
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		add_self(ans, mul(n - i, dp[i][s]));
	}

	cout << ans << endl;
}
