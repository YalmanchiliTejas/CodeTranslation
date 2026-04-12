#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

ll MOD = 1000000007;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll total = 0;
    rep(i, n) {
        cin >> a[i];
        total = (total + a[i]) % MOD;
    }

    ll ans = 0;
    rep(i, n) {
        total -= a[i];
        total += MOD;
        total %= MOD;
        ans += (a[i] * total) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}