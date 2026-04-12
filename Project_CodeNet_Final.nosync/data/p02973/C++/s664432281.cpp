#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1, i >= 0, i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

namespace mp = boost::multiprecision;

using ll = long long;
using ul = unsigned long long;
using Bint = mp::cpp_int;
ll mod = 1000000007;

int main() {
source:
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n) { cin >> a[i]; }
    rep(i, n) { a[i] = -a[i]; }

    ll dp[n];
    rep(i, n) { dp[i] = mod; }
    rep(i, n) { *upper_bound(dp, dp + n, a[i]) = a[i]; }
    ll ans = (lower_bound(dp, dp + n, mod) - dp);
    cout << ans << endl;
    return 0;
}

