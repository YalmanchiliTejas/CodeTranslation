#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> b(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        b[i] = (b[i + 1] + a[i+1]) % mod;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (a[i] * b[i]) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
