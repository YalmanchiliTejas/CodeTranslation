#include <bits/stdc++.h> // Ishaan Gupta
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cout << *x, 0);
sim > char dud(...);
struct debug {
#ifdef IG_PC
~debug() { cout << endl; }
eni(!=) cout << boolalpha << i; ris; }
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
#define endl '\n'
#define pb push_back
using ll = long long;
using ld = long double;
const ll MOD = 1e9l + 7;
const ll INF = 1e18l + 5;
inline ll add(ll a,ll b){return (a%MOD+b%MOD)%MOD;}
inline ll sub(ll a,ll b){return (a%MOD-b%MOD+MOD)%MOD;}
inline ll mult(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
inline ll power(ll a,ll b){a%=MOD;ll r=1;while(b){if(b&1)r=mult(r,a);a=mult(a,a);b>>=1;}return r;}

ll dp[3005][3005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
#ifdef IG_PC
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll &i : a)
        cin >> i;
    for(ll l = n-1;l >=0; --l)
    {
        for(ll r = l; r < n; r++)
        {
            if(l==r)
            {
                dp[l][r] = a[l];
            }
            else
            {
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }
    cout<< dp[0][n-1];

    return 0;
}