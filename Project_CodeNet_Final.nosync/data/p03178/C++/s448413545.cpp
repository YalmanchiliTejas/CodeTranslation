#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define sz(x) ((int)x.size())
#define EX0 exit(0);

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9 + 7;
const ll inf = 1e9 + 7;
const ll INF = 1e15;
const ld eps = 1e-9;
const db PI = atan(1) * 4;

template<typename T, typename S>inline bool upmin(T&a, const S&b) { return a > b ? a = b, 1 : 0; }
template<typename T, typename S>inline bool upmax(T&a, const S&b) { return a < b ? a = b, 1 : 0; }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return a;
	}
	ll ans = pow(a, b / 2);
	ans *= ans;
	ans *= b % 2 == 1 ? a : 1;
	return ans;
}

namespace SOLVE {
	string str;
	ll n, k;
	vector<vector<VLL>> state;

	ll count(ll index, ll tight, ll remainder) {
		if (state[index][tight][remainder] != -1) {
			return state[index][tight][remainder];
		}
		if (index == n) {
			return remainder == 0;
		}

		ll c = 0, thisdigit = str[index] - '0';
		
		ll countto = tight ? thisdigit : 9;

		REP(i, 0, countto + 1) {
			int thistight = (i == thisdigit) ? tight : 0;
			c += count(index + 1, thistight, (remainder + k - (i % k)) % k);
			c %= mod;
		}
		

		state[index][tight][remainder] = c;
		return c;
	}

	void main() {
		

		cin >> str >> k;
		n = str.length();
		state.resize(n + 5, vector<VLL>(2, VLL(k + 5, -1)));

		ll ans = count(0, 1, 0) - 1; // index, tight, remainder
		if (ans < 0) {
			ans += mod;
		}
		cout << ans << endl; // it counts the 0
		

	}
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	//    in(t);
	t = 1;
	while (t--) {
		SOLVE::main();

	}

	return 0;
}
