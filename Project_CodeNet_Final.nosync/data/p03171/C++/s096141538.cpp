#include "bits/stdc++.h"
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

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
const int oo = 1e9+7;


int main() {
    
    int n;
    scanf("%d", &n);
    
    vector<ll> nums(n);
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<vector<ll>> st(n, vector<ll>(n, 0));
    
    for(ll& i : nums) {
        scanf("%lld", &i);
    }
    
    for(int s = 0; s < n; ++s) {
        ll run = 0;
        for(int e = s; e < n; ++e) {
            run += nums[e];
            st[s][e] = run;
        }
    }
    
    // dp[s][e] - lo maximo que puedo conseguir si me toca
    // a mi y en la queue queda el intervalo [s, e)
    
    for(int s = n-1; s >= 0; s--) {
        dp[s][s] = nums[s];
        for(int e = s+1; e < n; ++e) {
            dp[s][e] = max(st[s][e] - dp[s+1][e], st[s][e] - dp[s][e-1]);
        }
    }
    
    printf("%lld\n", dp[0][n-1]-(st[0][n-1]-dp[0][n-1]));
    
    return 0;
}


