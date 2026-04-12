#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	for(int b = 1; b <= n; b++) {
		ans += (n / b) * max(0LL, b - k);
		ans += max(0LL, n % b - k + 1);
	}
	if(k == 0) ans -= n;
	cout << ans << endl;
	return 0;
}