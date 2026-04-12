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
#ifndef LOCAL
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

const int mod = (int) 1e9 + 7;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	long long sum = 0;
	for (long long &i : v) cin >> i;
	vector<long long> suf(n, 0);
	suf[n - 1] = v[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = (v[i] + suf[i + 1] % mod) % mod;
	}
	for (int i = 0; i < n - 1; i++) {
		sum = (sum % mod + suf[i + 1] % mod * v[i] % mod) % mod;
	}
		
	cout << sum << "\n";
}
