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
const int mod = 998244353;
using ll = long long;
const ll inf = 1e18+5;
ll ff(ll n, ll m) {
	return (ll)(n*n)%m;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, x, m;
	cin >> n >> x >> m;
	ll sum = 0, prev = x;
	bool zt = 0;
	set<int> c;
	vector<int> a;
	a.push_back(prev);
	c.insert(prev);
	for(ll i=0;i<n;i++) {
		sum+=prev;
		ll xx = ff(prev,m);
		if(xx == 0) {
			zt = 1;
			break;
		}
		if(c.count(xx)) {
			prev = xx;
			break;
		}
		else {
			c.insert(xx);
			a.push_back(xx);
			//sum+=xx;
		}
		prev = xx;
	}
	if(zt) {
		//zero term;
		cout<<sum;
		return 0;
	}
	debug()<<imie(a);
	int sz = (int)a.size();
	if(n <= (int)a.size()) {
		ll out = 0;
		for(int i=0;i<n;i++) {
			out+=a[i];
		}
		cout<<out;
		return 0;
	}	
	long long ans = sum;
	int st = -1;
	for(int i=0;i<sz;i++) {
		if(a[i] == prev) {
			st = i;
			break;
		}
	}
	n-=sz;
	ll sum2 = 0;
	for(int i=st;i<sz;i++) {
		sum2+=a[i];
	}	
	ll rev = sz-st;
	ans += (sum2 * (n/rev));
	n = n%rev;
	for(int i=st;i<(st+n);i++) {
		ans += a[i];
	}
	cout<<ans;
}
