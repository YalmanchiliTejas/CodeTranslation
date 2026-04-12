#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;


int main() {
	ll n, k; cin >> n >> k;
	ll ans = 0;
	if (k == 0) {
		cout << n*n << endl;
		return 0;
	}
	for (ll b = k + 1; b <= n; b++) {
		ans += (b - k)*(n / b) + (n%b == 0 ? 0 : max(0LL, n%b - k + 1));
	}
	cout << ans << endl;
	return 0;
}