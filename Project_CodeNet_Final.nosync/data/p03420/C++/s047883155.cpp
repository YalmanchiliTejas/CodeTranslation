#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <list>
#include <stack>
#include <set>
#include <cctype>

using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

#define ll long long
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;

	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}

	ll ans = 0;
	FOR(i, 1, n + 1) {
		if (i - 1 >= k) {
			ans += n / i * (i - k);
			ans += max(0LL, (n%i) - k + 1);
		}
	}
	cout << ans << endl;
	return 0;

}
