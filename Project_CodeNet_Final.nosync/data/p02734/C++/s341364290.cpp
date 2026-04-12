#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll base = 998244353;

int main() {
	int n, s; cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<ll> dp(s+1);
	ll total = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = s; j >= a[i]; --j) {
			if (j == a[i]) dp[j] = (dp[j] + i+1) % base;
			else dp[j] = (dp[j] + dp[j-a[i]]) % base;
		}
		total = (total + dp[s] * (n-i) % base) % base;
		dp[s] = 0;
	}

	cout << total << endl;
}
