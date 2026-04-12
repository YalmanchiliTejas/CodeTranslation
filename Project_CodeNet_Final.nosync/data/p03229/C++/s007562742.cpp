#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	ll ans = 0;
	int posiCnt;
	int negaCnt;
	int index = 0;
	if (n % 2 == 0) {
		posiCnt = n / 2 - 1;
		negaCnt = n / 2 - 1;		
		while (posiCnt--) {
			ans += 2 * a[index];
			index++;
		}
		ans += a[index];
		index++;
		ans += (-1) * a[index];
		index++;
		while (negaCnt--) {
			ans += (-2) * a[index];
			index++;
		}
	}
	else { // n % 2 != 0
		ll ans1 = 0;
		posiCnt = (n - 1) / 2;
		negaCnt = (n - 3) / 2;
		while (posiCnt--) {
			ans1 += 2 * a[index];
			index++;
		}
		ans1 += (-1) * a[index];
		index++;
		ans1 += (-1) * a[index];
		index++;
		while (negaCnt--) {
			ans1 += (-2) * a[index];
			index++;
		}
		ll ans2 = 0;
		index = 0;
		posiCnt = (n - 3) / 2;
		negaCnt = (n - 1) / 2;
		while (posiCnt--) {
			ans2 += 2 * a[index];
			index++;
		}
		ans2 += a[index];
		index++;
		ans2 += a[index];
		index++;
		while (negaCnt--) {
			ans2 += (-2) * a[index];
			index++;
		}
		ans = max(ans1, ans2);
	}
	cout << ans << endl;
    return 0;
}