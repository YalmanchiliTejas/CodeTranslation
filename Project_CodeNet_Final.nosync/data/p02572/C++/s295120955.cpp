#include <bits/stdc++.h>
using namespace std;

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long;
using pll = pair<ll, ll>;

const ll MOD = 1000000007LL;

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    rep (i, N) { cin >> A[i]; }

    ll sum = 0;
    rep (i, N) { sum += A[i]; }

    ll ans = 0;

    rep (i, N)
    {
        sum -= A[i];
        const auto x = A[i];
        const auto y = sum % MOD;

        ans += (x * y) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
