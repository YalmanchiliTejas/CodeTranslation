
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));
    vector<ll> ans(n);
    ll anss = 0;

    if(n % 2 == 0) {
        ll idx = 0, idx2 = 0;
        REP(i, n) {
            if(i % 2 == 0) {
                ans[i] = a[idx2 + n/2];
                idx2++;
            } else {
                ans[i] = a[idx];
                idx++;
            }
        }
        REP(i, n-1) {
            anss += abs(ans[i] - ans[i+1]);
        }
    } else {
        ll idx = 0, idx2 = 0;
        REP(i, n-1) {
            if(i % 2 == 0) {
                ans[i] = a[idx2 + n/2 + 1];
                idx2++;
            } else {
                ans[i] = a[idx];
                idx++;
            }
        }
        REP(i, n-2) {
            anss += abs(ans[i] - ans[i+1]);
        }
        anss = max(anss + abs(ans[0] - a[n/2]), anss + abs(ans[n-2] - a[n/2]));
    }

    cout << anss << endl;

    return 0;
}