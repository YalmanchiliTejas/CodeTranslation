#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e3+5, mod=998244353;

ll n, s, ans, a[sz], dp[sz][sz];

ll fnc(ll pos, ll rem)
{
    if(rem<0) return 0;
    if(!rem) return n-pos+1;
    if(pos==n) return 0;
    if(dp[pos][rem]!=-1) return dp[pos][rem];

    ll x = fnc(pos+1, rem-a[pos]);
    ll y = fnc(pos+1, rem);
    if(rem == s) ans += (pos+1) * x % mod, ans %= mod;
    return dp[pos][rem] = (x + y) % mod;
}

int main()
{
    cin >> n >> s;
    for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
    memset(dp, -1, sizeof(dp));
    fnc(0, s);
    cout << ans << endl;
}
