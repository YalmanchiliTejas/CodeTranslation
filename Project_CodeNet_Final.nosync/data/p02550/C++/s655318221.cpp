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

long long Pow(long long a ,long long m) {
	long long res = 1;
	res = (a * a) % m;
	return res;
}
int main() {
	long long n, x, m;
	cin >> n >> x >> m;
	vector<long long> v;
	v.push_back(x);
	long long start = 0;
	bool hasZ = false;
	for (int i = 1; i < n; i++) {
		long long temp = Pow(v[i - 1], m);
		if (find(v.begin(), v.end(), temp) != v.end()) {
			start = find(v.begin(), v.end(), temp) - v.begin();
			break;
		}
		if (!temp) hasZ = true;
		v.push_back(temp);
	}
	if (hasZ) {
		cout << accumulate(v.begin(), v.end(), 0ll) << "\n";
		return 0;
	}
	long long sumBefore = accumulate(v.begin(), v.begin() + start, 0ll);
	long long sumCycle = accumulate(v.begin() + start, v.end(), 0ll);
	long long res = sumBefore;
	res += (sumCycle * ((n - start) / ((int) v.size() - start)));
	long long rest = n - start - (((int) v.size() - start) * ((n - start) / ((int) v.size() - start)));
	while (rest--) {
		res += v[start];
		start++;
	}
	cout << res << "\n";
	return 0;
}
