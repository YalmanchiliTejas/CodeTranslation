#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define SORTD(a) sort(a.rbegin(), a.rend());
#define UNIQUE(a) unique(a.begin(), a.end())
#define ll long long
#define INF 1000000000000000000
#define INT_MAX 2147483647

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>
#include <ios>
#include <iomanip>
#include <sstream>

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

const ll mod = 1e9 + 7;

ll mpow(ll n, ll m) {
	if (n == 1)
		return m;

	ll ret = mpow(n / 2, m);
	ret = ret * ret % mod;
	if (n & 1)
		ret = ret * m%mod;

	return ret;
}

ll ncr(ll n, ll r) {
	ll ret = 1;
	for (int i = 1; i <= r; i++) {
		ret = ret * (n - i + 1) % mod;
		ret = ret * mpow(mod - 2, i) % mod;
	}
	return ret;
}


int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 0;

	for (int i = 1; i <= n - 1; i++) {
		ans = (ans + i * (n - i)*m*m) % mod;
	}
	for (int i = 1; i <= m - 1; i++) {
		ans = (ans + i * (m - i)*n*n) % mod;
	}

	cout << ans * ncr(n*m - 2, k - 2) % mod << endl;

}