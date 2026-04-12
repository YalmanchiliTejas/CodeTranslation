#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define FOR(a, b, c) for (int (a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))

int main() {
    ll n;
    cin >> n;
    vl a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll m = pow(10, 9) + 7;

    /*REP (i, n) {
        for (int j = i + 1; j < n; j++) {
            ans += a[i] * a[j];
            //cout << ans << endl;
        }
    }*/
    
    // Using math formula
    /*ll ts = 0, is = 0;
    for (ll i = 0; i < n; i++) {
        ts += a[i];
        is += a[i] * a[i];
    }
    ll tss = ts * ts;
    ans = (tss - is) / 2;
    cout << ans % m << endl;*/

    ll x = 0;
    REP (i, n) {
        ans = (ans + (ll)a[i] * x) % m;
        x = (x + a[i]) % m;
    }
    cout << ans << endl;
    return 0;
}
