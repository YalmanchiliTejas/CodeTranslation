
#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A & a, const B & b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A & a, const B & b) { a = max(a, (A)b); };

ll modpow(ll r, ll n, ll mod) {
	ll ans = 1;
	ll tmp = r;
	while (n > 0) {
		if ((n & 1) > 0) ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}


int main() {
	ll N, X, M; cin >> N >> X >> M;
	vector<ll> tbl(2*M + 1);
	unordered_map<ll, ll> mp;
	ll loopstart;
	ll loopend;
	tbl[1] = X % M;
	mp[X % M] = 1;
	REP(i, 2, 2*M+1) {
		ll tmp = tbl[i-1] * tbl[i-1] % M;
		if (mp.count(tmp) > 0) {
			loopstart = mp[tmp];
			loopend = i - 1;
			break;
		}
		tbl[i] = tmp;
		mp[tmp] = i;
	}
	if (N <= loopend) {
		ll ans = 0;
		REP(i, 1, N+1) ans += tbl[i];
		PRI(ans);
		return 0;
	}
	ll looplen = loopend - loopstart + 1;
	ll loopn = (N - loopstart + 1) / looplen;
	ll amari = N - loopstart + 1 - looplen * loopn;
	ll ans = 0;
	REP(i, 1, loopstart) ans += tbl[i];
	REP(i, loopstart, loopend + 1) ans += loopn * tbl[i];
	REP(i, loopstart, loopstart + amari) ans += tbl[i];
	PRI(ans);
	return 0;
}