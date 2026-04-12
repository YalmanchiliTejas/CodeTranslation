#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << " = "<< x << "\n";

const int mod = 1000000007;
signed main() {
//	freopen("in.txt", "r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	int a[n];
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int ans = 0;
	int sum = 0;
	
	for(int i = 0; i < n; i++) {
		ans += (a[i] * sum) % mod;
		ans %= mod;
		sum += a[i];
		sum %= mod;
	}
	
	cout << ans;
}
