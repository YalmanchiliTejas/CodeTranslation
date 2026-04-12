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

#define FOR(i, b, e) for(int i = (int)(b); i < (int)(e); ++i)
#define RFOR(i, b, e) for(int i = (int)(e-1); i >= (b); --i)
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
#define PAIR pair<int,int>
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


int main() {
	int n, k;
	cin >> n >> k;

	ll s = 0;
	RFOR(b, 1, n + 1) {
		if (b < k) { break; }
		ll d = n % b;
		ll l = n / b;
		s += (b - k)*l;
		if (d >= k) { s += (d - k + 1); }
	}
	cout << ((k == 0) ? s - n : s) << endl;
}