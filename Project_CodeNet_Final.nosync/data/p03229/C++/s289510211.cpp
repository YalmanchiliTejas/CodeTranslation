#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>

#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define VS vector<string>
#define VL vector<long long>
#define VI vector<int>
#define VVI vector<vector<int>>
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define PAIR pair<ll,ll>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using  ll = long long;
constexpr int MOD = 1000000007;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

VL prime_decomposition(ll n) {
	ll i = 2;
	VL table{};
	while (i * i <= n) {
		while (n % i == 0) {
			n /= i;
			table.emplace_back(i);
		}
		++i;
	}
	if (n > 1) {
		table.emplace_back(n);
		return table;
	}
}

ll compMax(const VL& a, const VL& b, ll tmp) {

	ll size = a.size();
	ll tmpa = 0;
	REP(i, size) {
		tmpa += b[i] - a[i];
		if (i > 0) {
			tmpa += b[i - 1] - a[i];
		}
	}
	if (tmp != 0) {
		tmpa = std::max(tmpa + tmp - a[0], tmpa + b[size - 1] - tmp);
	}
	ll tmpb = 0;
	REP(i, size) {
		tmpb += b[i] - a[i];
		if (i > 0) {
			tmpb += b[i] - a[i - 1];
		}
	}
	if (tmp != 0) {
		tmpb = std::max(tmpb + b[0] - tmp, tmpb + tmp - a[size - 1]);
	}

	return max(tmpa, tmpb);
}

int main() {
	ll n;
	cin >> n;
	VL v(n);
	REP(i, n) { cin >> v[i]; }

	sort(ALL(v));

	VL a, b;
	a.reserve(n / 2);
	b.reserve(n / 2);
	RREP(i, n) {
		if (i < n / 2) {
			a.emplace_back(v[i]);
		} else if (i >= n / 2) {
			b.emplace_back(v[i]);
		}
	}

	ll tmp = 0;
	if (n % 2 == 1) {
		tmp = b[n / 2];
		b.pop_back();
	}

	ll max = 0;
	max = std::max(max, compMax(a, b, tmp));

	VL t = a;
	sort(ALL(a));
	max = std::max(max, compMax(a, b, tmp));

	sort(ALL(b));
	max = std::max(max, compMax(t, b, tmp));

	max = std::max(max, compMax(a, b, tmp));

	cout << max << endl;
}