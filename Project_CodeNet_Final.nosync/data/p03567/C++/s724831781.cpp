#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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



int main() {
	string s;
	cin >> s;
	for(int i = 0; i < (int) s.length() - 1; ++i)
		if(s[i] == 'A' && s[i+1] == 'C') {
			puts("Yes");
			return 0;
		}
	puts("No");
	
	//~ int n;
	//~ cin >> n;
	//~ int odd = 1, even = 0;
	//~ while(n--) {
		//~ int x;
		//~ cin >> x;
		//~ if(x % 2) {
			//~ even = 2 * (even + odd) + even;
			//~ odd = odd
		//~ }
		//~ else {
			
		//~ }
	//~ }
	//~ printf("%d\n", even);
}
