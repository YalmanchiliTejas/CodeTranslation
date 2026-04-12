#include <bits/stdc++.h>
using namespace std;


#define int long long 


const int mod = 1e9 + 7;


int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 0, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x; x %= mod;
		ans += sum * x % mod;
		ans %= mod;
		sum += x;
		sum %= mod;
	}

	cout << ans << endl;
}
