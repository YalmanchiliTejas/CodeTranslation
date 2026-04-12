
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    ll ans = 0;
    ll n, k;
    cin >> n >> k;
    if(k == 0) {
        cout << n * n << endl;
        return 0;
    }
    REPN(waru, k+1, n+1) {
        ans += (n / waru) * (waru - k);
        ll tmp = n % waru;
        tmp -= k - 1;
        tmp = max((ll)0, tmp);
        ans += tmp;
        //cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}