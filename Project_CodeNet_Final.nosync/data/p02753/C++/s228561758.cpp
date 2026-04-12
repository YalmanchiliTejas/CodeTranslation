#include <bits/stdc++.h>
#define int long long 
#define float long double 
#define el '\n'
#define all(a) (a).begin(),(a).end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

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
 
void solve(){
	string s ;
	cin >> s ;
	if(all_of(all(s),[&](char a){ return a == s[0]; } )){
		cout << "No" << endl; 
	}else{
		cout << "Yes" << endl; 
	}
}

signed main(){
	IOS;
	int test = 1; 
	while(test--)
		solve();
	return 0;
}





