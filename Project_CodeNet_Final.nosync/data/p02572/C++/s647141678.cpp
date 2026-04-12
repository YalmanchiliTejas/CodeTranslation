#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	cin >> n;
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<ll> sum(n + 1, 0LL);
	for(int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] % MOD_LL + a[i] % MOD_LL;
		sum[i + 1] %= MOD_LL;
	}
	
	ll ans = 0LL;
	for(int i = 0; i < n - 1; ++i) {
		ans += (a[i] % MOD_LL) * ((sum[n] - sum[i + 1]) % MOD_LL);
		ans %= MOD_LL;
	}
	
	if( ans < 0 ) ans += MOD_LL;
	
	cout << ans << endl;
	
	return 0;
}
