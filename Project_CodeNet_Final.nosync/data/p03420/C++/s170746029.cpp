#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

main(void) {
	int n , k , ans = 0;
	cin >> n >> k;
	for(int b = k + 1;b <= n;++ b) {
		int now = n / b;
		ans += max(n - now * b - k + 1 , 0ll);
		-- now;
		ans += (now + 1) * (b - k);
	}
	if(!k) ans -= n;
	cout << ans;
}