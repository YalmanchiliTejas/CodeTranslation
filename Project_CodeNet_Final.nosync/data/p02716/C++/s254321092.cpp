#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#ifndef LOCAL
#define endl '\n'
#endif

const int mod = 1e9 + 7;

int pwr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

const int N = 2e5 + 5;
int a[N];
ll pre_e[N], pre_o[N];
ll dp_even[N], dp_odd[N];

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre_e[i] = pre_e[i - 1];
		pre_o[i] = pre_o[i - 1];
		if(i & 1)
			pre_o[i] += a[i];
		else
			pre_e[i] += a[i];
	}
	ll maxi = -1e18;
	dp_even[2] = max(a[1], a[2]);
	for(int i = 4; i <= n; i += 2) {
		maxi = max(maxi, pre_o[i - 3] - pre_e[i - 1]);
		dp_even[i] = pre_e[i];
		dp_even[i] = max(dp_even[i], pre_e[i] + maxi);
	}
	if(n % 2 == 0) {
		cout << dp_even[n];
		return ;
	}
	for(int i = 3; i <= n; i += 2) {
		dp_odd[i] = -1e18;
		dp_odd[i] = max(dp_odd[i], pre_o[i]);
		dp_odd[i] = max(dp_odd[i], dp_odd[i - 2] + a[i]);
		dp_odd[i] = max(dp_odd[i], dp_even[i - 3] + a[i - 1]);
	}
	cout << dp_odd[n];
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	for(int tt = 1; tt <= t; tt++) {
		solve();
	}
	return 0;
}