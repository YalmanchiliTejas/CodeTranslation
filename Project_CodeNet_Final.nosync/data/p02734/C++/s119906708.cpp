#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cassert>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()
#define sz(x) ((int)((x).size()))
#define pb push_back
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
typedef short int sint;

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
  for (auto it = d.b; it != d.e; ++it) {
	*this << ((it != d.b) ? ", " : "") << *it;
  }
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;
	vi a(n + 1);
	FOR(i, 1, n) cin >> a[i];
	vector<vi> f(n + 1, vi(s + 1, 0));
	ll res = 0;
	f[0][0] = 1;
	FOR(i, 1, n) {
		REP(ss, s + 1) {
			f[i][ss] = f[i - 1][ss];
			if (ss >= a[i]) {
				f[i][ss] = (f[i][ss] + f[i - 1][ss - a[i]]) % mod;
			}
			// printf("f[%d][%d] = %d\n", i, ss, f[i][ss]);
		}
		++f[i][0];
		res = (res + f[i][s]) % mod;
	}
	cout << res << endl;
}