#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll pans(int lv, ll n) {
	if (lv == 0) {
		return 1;
	}
	if (n == 1) {
		return 0;
	}
	ll all = (1LL << (lv + 2)) - 3;
	ll mid = all / 2 + 1;
	if (n < mid) {
		return pans(lv - 1, n - 1);
	} else if (n == mid) {
		return pans(lv - 1, n - 2) + 1;
	} else {
		return ((1LL << lv) - 1) + 1 + pans(lv - 1, n - mid);
	}
}
int main() {
	ll n, x;
	cin >> n >> x;
	cout << pans(n, x) << endl;
	return 0;
}