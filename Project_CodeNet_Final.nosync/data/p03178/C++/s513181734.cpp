#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e4 + 5, M = 1e2 + 2, T = 10 + 1, mod = 1e9 + 7;

string s;
int D, dp[N][M][T];

int sum(int a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> s >> D;
	int n = s.size();
	for (int i = 0; i < 10; i++)
		dp[1][i % D][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < D; j++) {
			for (int k = 0; k < 10; k++) {
				int rem = (((j - k) % D) + D) % D;
				for (int v = 0; v < 10; v++)
					dp[i][j][k] = sum(dp[i][j][k], dp[i - 1][rem][v]);
			}
		}
	}
	int ans = 1e9 + 6;
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < (s[i] - '0'); j++)
			ans = sum(ans, dp[n - i][(D - cur) % D][j]);
		cur += s[i] - '0';
		cur %= D;
	}
	if(cur % D == 0)
		ans = sum(ans, 1);
	cout << ans << "\n";
}
