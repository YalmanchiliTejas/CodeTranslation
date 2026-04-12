#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>h(n);
	for (int i = 0; i < n; i++)cin >> h.at(i);
	ll cur = h.at(0);
	ll ans = 1;
	for (int i = 1; i < n; i++) {
		if (h.at(i) >= cur) {
			ans++;
			cur = h.at(i);
		}
	}
	cout << ans << endl;
}