#include <bits/stdc++.h>
using namespace std;
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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }



int main() {
	long long n;
	int x, mod;
	cin >> n >> x >> mod;
	vector<int> pos(mod, -1);
	long long sum = x;
	vector<long long> pref{x};
	pos[x] = 0;
	for(long long i = 1; i < n; ++i) {
		x = (long long) x * x % mod;
		sum += x;
		pref.push_back(pref.back() + x);
		if(pos[x] == -1) {
			pos[x] = i;
		}
		else {
			int cycle = i - pos[x];
			long long times = max(0LL, (n - i - 2) / cycle);
			if(times > 0) {
				sum += (pref[i] - pref[pos[x]]) * times;
				i += times * cycle;
			}
		}
	}
	printf("%lld\n", sum);
}
