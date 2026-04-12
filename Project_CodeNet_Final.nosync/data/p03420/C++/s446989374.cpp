#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
	ll n,k;
	ll ans = 0;
	cin >> n >> k;
	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}

	for (ll b = k + 1; b <= n; b++) {
		ll s = (n / b) * b;

		ans += max(0LL, (n / b) * (b - k));
		//cout << "b:" << b << " s:" << s << " ans1:" << (n / b) * (b - k) << endl;
		if (n - s >= 1) {

			ans += max(n - s - k + 1, 0LL);
			//cout << "ans1:" << max(n - s - k, 0) << endl;
		}
		//cout << "b:" << b << " s:" << s << " ans1:" << (n / b) * (b - k) << " ans0:"  << n - s - k + 1 << endl;
		
	}
	cout << ans << endl;
	return 0;
}