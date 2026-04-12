#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 3e3 + 5;
const int mod = 1e9 + 7;
int n, k, a[N];
ll dp[N][N];
bool bo[N][N];
void cal(int l, int r, int f) {
	if (bo[l][r]) return;
	if (l > r) return;
	cal(l + 1, r, 1 - f);
	cal(l, r - 1, 1 - f);
	if (f) {
		dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r]);	
	} else {
		dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r]);
	}
	bo[l][r] = 1;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cal(1, n, 1);
	cout << dp[1][n];
}
