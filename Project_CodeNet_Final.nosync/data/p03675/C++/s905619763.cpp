#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;
typedef long long int ll;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, a, ans[200020];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (n % 2) {
			if (i % 2) ans[n / 2 + 1 - i / 2] = a;
			else ans[n / 2 + 1 + i / 2] = a;
		}
		else {
			if (i % 2) ans[n / 2 + 1 + i / 2] = a;
			else  ans[n / 2 + 1 - i / 2] = a;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i != n)cout << ans[i] << " ";
		else cout << ans[i] << endl;
	}
	return 0;
}