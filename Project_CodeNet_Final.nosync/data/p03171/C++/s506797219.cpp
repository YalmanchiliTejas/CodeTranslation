#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXN = 3005;
const int INF = (LL)1e9 + 5;
const LL MOD = 998244353;

int N, a[MAXN];
LL dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int l = N - 1; l >= 0; l--) {
		for (int r = l + 1; r <= N; r++) {
			dp[l][r] = max(a[l] - dp[l + 1][r], a[r - 1] - dp[l][r - 1]);
		}
	}
	
	cout << dp[0][N] << "\n";
}
