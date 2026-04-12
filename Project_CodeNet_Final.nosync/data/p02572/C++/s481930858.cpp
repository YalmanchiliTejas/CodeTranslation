#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>

#define FastIO 						\
		ios::sync_with_stdio(0); 	\
		cin.tie(NULL); 				\
		cout.tie(NULL);

using namespace std;

typedef long long ll;

#define MOD 1000000007

void solve() {
	int n;
	cin >> n;
	ll a[n] = {}, b[n + 1] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i > 0; i--) {
		b[i] = b[i + 1] + a[i];
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ((a[i] % MOD) * (b[i + 1] % MOD)) % MOD;
		sum %= MOD;
	}
	cout << (sum % MOD) << "\n";
}

int main() {
	// FastIO;
	int n = 1;
	// cin >> n;
	while (n--) {
		solve();
	}
}
