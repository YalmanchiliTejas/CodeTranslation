#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>
//#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;
using pis = std::pair<int, std::string>;

const long long INF = 1000000000000000001;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

using namespace std;
//namespace mp = boost::multiprecision;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int k;
	cin >> k;

	ll dp_t[4] = { 0 };
	ll dp_f[4] = { 0 };

	dp_t[1] = 1;
	dp_f[1] = s[0] - '1';

	REP(i, 1, s.length()) {
		RREP(j, 1, k) dp_f[j + 1] += dp_f[j] * 9;
		dp_f[1] += 9;

		if (s[i] != '0') {
			REP(j, 1, k + 1) dp_f[j] += dp_t[j];
			REP(j, 1, k) dp_f[j + 1] += dp_t[j] * (s[i] - '1');

			RREP(j, 1, k) dp_t[j] = dp_t[j - 1];
		}
	}

	cout << dp_f[k] + dp_t[k] << "\n";

	return 0;
}
