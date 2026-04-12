#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[212345];
ll n, sum, ans;
const ll mod = 1e9 + 7;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i)sum += a[i];
	sum %= mod;
	for (int i = 0; i < n; ++i) {
		sum -= a[i];
		ans += (sum % mod) * a[i];
		ans %= mod;
	}
	if (ans < 0)ans += mod;
	cout << ans << endl;
	return 0;
}