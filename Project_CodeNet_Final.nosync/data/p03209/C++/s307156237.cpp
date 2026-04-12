#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, x;
	cin >> n >> x;

	ll numP[51], num[51];
	numP[0] = 1;
	num[0] = 1;
	for (int i = 1;i <= 50;i++) {
		numP[i] = 2 * numP[i - 1] + 1;
		num[i] = 2 * num[i - 1] + 3;
	}

	ll ans = 0;
	while (n > 1) {
		if (x == 1) {
			cout << ans << endl;
			return 0;
		}
		if (x <= 1 + num[n - 1]) {
			n--;
			x--;
			continue;
		}
		ans += numP[n - 1];
		ans++;
		if (x == 2 + num[n - 1]) {
			cout << ans << endl;
			return 0;
		}
		if (x <= 2 * num[n - 1] + 2) {
			x -= 2 + num[n - 1];
			n--;
			continue;
		}
		ans += numP[n - 1];
		cout << ans << endl;
		return 0;
	}
	if (x >= 2 && x <= 4) {
		ans += x - 1;
	}
	if (x == 5) {
		ans += 3;
	}

	cout << ans << endl;



	return 0;
}