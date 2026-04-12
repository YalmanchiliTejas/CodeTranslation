#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int main() {
	ll n, k, ans = 0;
	cin >> n >> k;
	if (k == 0)cout << n * n << endl;
	else {
		for (int i = k + 1; i <= n; i++) {
			ll num = n / i;
			ans += num * (i - k);
			num = n - num * i;
			if (num >= k)ans += num - k + 1;
		}
		cout << ans << endl;
	}
	return 0;
}