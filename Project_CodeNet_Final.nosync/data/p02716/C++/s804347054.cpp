#include "bits/stdc++.h"

using namespace std;

#define pi 3.1415926535
#define ll long long
#define mod 1000000007



int main() {
	ll n;
	int i;
	ll a[200010];
	ll data[200010];
	ll dp[200010];
	ll stk1, stk2;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	data[1] = a[1];
	dp[0] = 0;
	dp[1] = 0;
	for (i = 3; i <= n; i+=2) {
		data[i] = data[i - 2] + a[i];
	}
	for (i = 2; i <= n; i++) {
		if (i & 1) {
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		}
		else {
			dp[i] = max(dp[i - 2] + a[i], data[i - 1]);
		}
	}
	//if (n & 1) dp[n] = max(dp[n], data[n] - data[1]);;
	cout << dp[n];
	return 0;
}