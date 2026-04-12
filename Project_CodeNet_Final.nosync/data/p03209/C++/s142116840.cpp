#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pat(ll n, ll x,vector<ll>total) {
	ll ans;
	if (n == 0 && x == 1)return 1;
	if (x <= 1)ans = 0;
	else if (x <= 1 + total.at(n - 1))ans = pat(n - 1, x - 1, total);
	else if (x <= 2 + total.at(n - 1))ans = pat(n - 1, total.at(n - 1), total) + 1;
	else if (x <= 2 + total.at(n - 1) * 2)ans = pat(n - 1, total.at(n - 1), total) + 1 + pat(n - 1, x - total.at(n - 1) - 2, total);
	else ans = pat(n - 1, total.at(n - 1), total) * 2 + 1;
	return ans;
}

int main() {
	ll n, x;
	cin >> n >> x;
	vector<ll>total(51);
	for (int i = 0; i < 51; i++) {
		if (i == 0)total.at(i) = 1;
		else total.at(i) = total.at(i - 1) * 2 + 3;
	}
	ll ans = pat(n, x,total);
	cout << ans << endl;
}