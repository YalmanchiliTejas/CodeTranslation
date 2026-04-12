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
const int MOD = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int N, arr[200000];
ll dp[200000][3];

ll go(int idx, int rest) {
	if (idx + rest >= N) return 0;

	ll &ret = dp[idx][rest];
	if (ret != -1) return ret;

	ret = -0x3f3f3f3f3f3f3f3fll;
	for (int i = 0; i <= rest; ++i)
		ret = max(ret, arr[idx + i] + go(idx + i + 2, rest - i));

	return ret;
}
int main() {
	fastio; ini(dp, -1);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	if (~N & 1) cout << go(0, 1);
	else cout << go(0, 2);

	return 0;
}
