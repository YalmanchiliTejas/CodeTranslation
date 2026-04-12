#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007;

int main() {
	int n;
	long long int val, sum = 0, ans = 0 ;
	vector<long long int> nums, suffix;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		nums.push_back(val);
	}

	suffix.resize(n, 0);
	for (int i = n-1; i >= 0; i--) {
		sum = (sum + nums[i])%mod;
		suffix[i] = sum;
	}
	
	for (int i = 0; i < n - 1; i++) {
		ans = (ans + (nums[i] * suffix[i+1])%mod) % mod;
	}
	cout << ans;
	
	return 0;
}
