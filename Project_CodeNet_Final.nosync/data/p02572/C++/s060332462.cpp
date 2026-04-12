#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int sum[n];
	sum[n - 1] = arr[n - 1];
	for (int i = n - 2; i > -1; i--) {
		sum[i] = sum[i + 1];
		sum[i] = (1LL * sum[i] + 1LL * arr[i]) % mod;
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans = (1LL * ans + 1LL * arr[i] * sum[i + 1]) % mod;
	}
	cout << ans;
	return 0;
}
