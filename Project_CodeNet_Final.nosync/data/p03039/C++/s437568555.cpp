#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
#include<time.h>
#include<cassert>
#include<functional>
#include<numeric>
#include <tuple>

using namespace std;
using ll = long long;
using ld = long double;
#define int long long
#define all(a) (a).begin(),(a).end()
#define EPS (1e-13)
#define fs first
#define sc second
#define xx first
#define yy second.first
#define zz second.second
#define H pair<int, int>
#define P pair<int, pair<int, int>>
#define Q(i,j,k) mkp(i,mkp(j,k))
#define rep(i,n) for(int (i) = 0 ; (i) < (n) ; (i)++)
#define rng(i,s,n) for(int (i) = (s) ; (i) < (n) ; (i)++)
#define req(i,n) for(int (i) = (n) - 1 ; (i) >= 0 ; (i)--)
#define mkp make_pair
#define mem0(x) memset(x,0,sizeof(x))
#define vec vector
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define crdcomp(b) sort(all((b)));(b).erase(unique(all((b))),(b).end())
#define ssp(i,n) (i==n-1?"\n":" ")
#define ctoi(c) (int)(c-'A')
#define itoc(c) (char)(c+'A')
#define pb push_back
#define cauto const auto&
#define itn int
#define pri_que priority_queue
#define pp(x,y) pb(H{x,y})
#define ppp(x,y,z) pb(Q(x,y,z))
const int mod = 1e9 + 7;
const int Mod = 998244353;
const ll inf = 3 * 1e18;
const int Inf = 15 * 1e8;
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }
ll read() { ll u, k = scanf(" %lld", &u); return u; }
string reads() { string s; cin >> s; return s; }
ll gcd(ll i, ll j) { return j ? gcd(j, i % j) : i; }
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}//x^n%p
ll bitcount(ll x) {
	int sum = 0; for (int i = 0; i < 60; i++)if ((1ll << i) & x) sum++;
	return sum;}
const int fn_ = 600000;
ll fact_[fn_], comp_[fn_];
ll comb(ll x, ll y, ll Mod = mod) {
	if (!fact_[0]) {
		fact_[0] = 1; comp_[0] = 1;
		for (int i = 1; i < fn_; i++) {
			fact_[i] = fact_[i - 1] * i % Mod;
			comp_[i] = mod_pow(fact_[i], Mod - 2, Mod);
		}
	}
	if (x < y) return 0;
	return fact_[x] * comp_[x - y] % Mod * comp_[y] % Mod;
}
//---------------------------------------------------------------
int n, m, k;
signed main() {
	cin >> n >> m >> k;
	int ans = 0;
	rng(i, 1, n) {
		ans += comb(n * m - 2, k - 2) * i * (n - i) % mod * m * m % mod;
		ans %= mod;
	}
	rng(i, 1, m) {
		ans += comb(n * m - 2, k - 2) * (m - i) % mod * n * n % mod * i;
		ans %= mod;
	}
	cout << ans << endl;
}