#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<long long> a(n);
	long long sum = 0;
	
	for(long long &x : a) {
		cin >> x;
		sum += x;
		sum %= mod;
	}
	
	long long ans = 0;
	
	// 1 * 2 + 1 * 3 = 1 (2 + 3)
	
	for(int i = 0; i < n - 1; i++) {
		
		sum -= a[i];
		sum = (sum + mod) % mod;
		
		long long temp = (a[i] * sum) % mod;
		ans = (ans + temp) % mod;
	}
	
	cout << ans << '\n';
	return 0;
}
