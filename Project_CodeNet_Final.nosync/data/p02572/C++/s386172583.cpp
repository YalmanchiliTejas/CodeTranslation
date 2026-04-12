#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vs = vector<string>;
#define all(x) x.begin(), x.end()
// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vi a(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		sum -= a[i];
		sum += MOD;
		sum %= MOD;
		ans += a[i] * sum;
		ans %= MOD;
	}
	cout << ans << endl;
}
