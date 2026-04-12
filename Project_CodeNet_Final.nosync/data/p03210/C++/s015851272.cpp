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
#include <bitset>

#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= (ll)(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define VS vector<string>
#define VL vector<long long>
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVL vector<vector<ll>>
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define PAIR pair<ll,ll>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using  ll = long long;
//constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::pair;
using std::string;
using std::stack;
using std::queue;
using std::vector;
using std::list;
using std::map;
using std::unordered_map;
using std::multimap;
using std::unordered_multimap;
using std::set;
using std::unordered_set;
using std::multiset;


// ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// ll pow(ll a, ll b) { ll ans = 1; while (b > 0) { if (b % 2 == 1) { ans *= a; ans %= MOD; }b /= 2; a *= a; a %= MOD; }return ans%MOD; }
// ll comb(ll n, ll r) { if (n - r < r) { return comb(n, n - r); }static VVL memo = {{1}}; if (memo.size() < n + 1) { memo.reserve(n + 1); FOR(i, memo.size(), n + 1) { memo.emplace_back(i + 1, 0); REP(j, i + 1) { memo[i][j] = 0;	if (j < i) { memo[i][j] += memo[i - 1][j]; }if (j > 0) { memo[i][j] += memo[i - 1][j - 1]; }memo[i][j] %= MOD; } } }return memo[n][r]; }
// ll comb_L(ll a, ll b) { if (a - b < b) { return comb(a, a - b); }static unordered_map<ll, ll> memo; ll c = 1; FOR(i, a - b + 1, a + 1) { c *= i; c %= MOD; }if (memo.find(b) == memo.end()) { ll k = 1; FOR(i, 2, b + 1) { k *= i;	k %= MOD; }memo[b] = pow(k, MOD - 2); }	c *= memo[b]; return c % MOD; }
// multiset<ll> prime_decomposition(ll n) { ll i = 2; multiset<ll> table{}; while (i * i <= n) { while (n % i == 0) { n /= i;	table.emplace(i); }++i; }if (n > 1) { table.emplace(n); return table; }return table; }
//-- bit -- REP(i, (1 << n)) {REP(j, n) {cout << (1 & (i >> j));}cout << endl;}

//==============================================================================================


int main() {
	ll n;
	cin >> n;
	cout << ((n == 3 || n == 5 || n == 7) ? "YES" : "NO") << endl;
}