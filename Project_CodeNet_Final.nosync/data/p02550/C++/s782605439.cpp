#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair <int, int> ii;
typedef pair <ll, int> lli;
#define ar array
#define pb push_back
#define fi first
#define se second
#define sz size
#define mp make_pair
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define int_max numeric_limits<int>::max()
#define int_min numeric_limits<int>::min()
#define ll_max numeric_limits<ll>::max()
#define ll_min numeric_limits<ll>::min()

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

// custom sort example
//sort(all(a), [ ]( const auto& c, const auto& d) {
	//if (c.fi.se != d.fi.se) {
		//return c.fi.se < d.fi.se; // lower first
	//}
	//if (c.fi.fi != d.fi.fi) {
		//return c.fi.fi > d.fi.fi; // higher first
	//}
	//return c.se > d.se; // higher first
//});

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T>
auto lbf(const std::set<std::pair<T, T>>& s, T first)
{
   static constexpr T min = std::numeric_limits<T>::min();

   return s.lower_bound({first, min});
}

int MOD = 998244353;

ll pw(ll n, ll k) {
	ll r = 1;
	for(; k; k >>= 1) {
		if(k&1) r = r * n % MOD;
		n = n * n % MOD;
	}
	return r;
}
ll inv(ll n) { return pw(n, MOD-2); }

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	ll n, x, m;
	cin >> n >> x >> m;
	ll res = 0;
	vector<lli> dp(m);
	for (int i = 0; i < m; i++) {
		dp[i] = {-1, -1};
	}
	for (ll i = 0; i < n; i++) {
		if (i == 0) {
			res = res + x;
			x = x * x;
		} else {
			res = res + x % m;
			if (dp[x % m].fi != -1) {
				ll pom = i - dp[x % m].se;
				ll pom2 = res - dp[x % m].fi;
				ll todo = n - i - 1;
				res = res + todo / pom * pom2;
				x = (x % m) * (x % m);
				for (int j = 0; j < todo % pom; j++) {
					res = res + x % m;
					x = (x % m) * (x % m);
				}
				break;
			}
			dp[x % m] = {res, i};
			x = (x % m) * (x % m);
		}
		if (x == 0) {
			break;
		}
	}
	cout << res << nl;
}
