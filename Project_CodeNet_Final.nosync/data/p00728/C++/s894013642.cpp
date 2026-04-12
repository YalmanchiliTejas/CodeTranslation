#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

int main(void) {
	while (true) {
		ll n;
		cin >> n;
		if (n == 0)break;
		vector<ll> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		sort(s.begin(), s.end());
		ll ans = 0;
		for (int i = 1; i < n - 1; i++) {
			ans += s[i];
		}
		ans /= (n - 2);
		cout << ans << endl;
	}
	return 0;
}
