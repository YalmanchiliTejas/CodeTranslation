#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;

ll n, ans, a, maxi;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	while(n--) {
		cin >> a;
		ans += (a >= maxi);
		maxi = max(maxi, a);
	}
	cout << ans;
	return 0;
}