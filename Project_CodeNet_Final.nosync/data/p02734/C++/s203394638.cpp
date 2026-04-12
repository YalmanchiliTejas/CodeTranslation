#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 998244353;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
	fastio;
	int N, S;
	cin >> N >> S;

	int arr[3001];
	for (int i = 1; i <= N; ++i) cin >> arr[i];

	int dp[3001]{}, ans = 0;
	for (int i = 1; i <= N; ++i) {
		dp[0] = i;
		for (int j = S; j >= arr[i]; --j) dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
		ans = (ans + dp[S]) % MOD;
	}

	cout << ans;

	return 0;
}