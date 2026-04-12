#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	if (n % 2 == 0) {
		rep(i, n) {
	        if (i < n / 2 -1) ans -= 2 * a[i];
			else if(i > n/2) ans += 2 * a[i];
			else if (i == n / 2 - 1) ans -= a[i];
			else ans += a[i];
		}
	}
	else {
		rep(i,n){
			if (i < n / 2 - 1) ans -= 2 * a[i];
			else if (i > n / 2 + 1) ans += 2 * a[i];
		}
		ll ans_a = ans, ans_b = ans;
		ans_a += a[n / 2 + 1] + a[n / 2] - 2 * a[n / 2 - 1];
		ans_b += 2 * a[n / 2 + 1] - a[n / 2] - a[n / 2 - 1];
		ans = max(ans_a, ans_b);
	}
	cout << ans << endl;
}