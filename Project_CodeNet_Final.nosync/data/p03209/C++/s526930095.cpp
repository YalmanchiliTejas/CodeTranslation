#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <queue>
using namespace std;

typedef int64_t ll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define vll vector<ll>
#define all(v) v.begin(), v.end()




int main() {
	ll N, X;
	cin >> N >> X;

	ll n = N, x = X - 1, len_n = (1ull << (n + 2)) - 3, ans = 0;
	while(true) {
		if (n == 0) { ++ans; break; }
		else if (x == 0) break;
		else if (x == (len_n - 1) / 2) { ans += 1ull << n;	break; }
		else if (x == len_n - 1) { ans += (1ull << (n + 1)) - 1; break; }

		else if (x < (len_n - 1) / 2) --x;
		else {
			ans += 1ull << n;
			x -= (1ull << (n + 1)) - 1;
		}
		len_n = (len_n - 3) / 2;
		--n;
	}

	cout << ans << endl;
}
