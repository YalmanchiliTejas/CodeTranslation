#include<bits/stdc++.h>
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
#ifndef ONLINE_JUDGE
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
using ll = long long;
using ull = unsigned long long int;
const int mod = 1e9+7;
int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ull> suff(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	suff[n-1] = a[n-1];
	for(int i = n-2;i>=0;--i) {
		suff[i] = (suff[i+1]%mod + a[i]%mod)%mod;
	}
	ull ans = 0;
	for(int i=0;i<n-1;i++) {
		ans = (ans + ((suff[i+1]%mod)*(a[i]%mod))%mod)%mod;
	}
	cout<<ans;
}
