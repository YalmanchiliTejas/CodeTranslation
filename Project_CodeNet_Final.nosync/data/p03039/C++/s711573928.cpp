#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
#define mod 1000000007
#define MAXN 200005
ll Pow(ll a, ll n) {
    if (n == 0) return 1;
    if (n % 2) return (a * Pow(a, n - 1)) % mod;
    else {
        ll k = Pow(a, n / 2);
        return (k * k) % mod;
    }
}
ll gyakusuu[MAXN + 1];
ll nCk(ll n, ll k) {
    if (k > n) return 0;
    ll ret = 1;
    for (ll i = 1; i <= k; i++) {
        ret = ret * (n - k + i) % mod;
        ret = ret * gyakusuu[i] % mod;
    }
    return ret;
}
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= MAXN; i++) {
        gyakusuu[i] = Pow(i, mod - 2);
    }
    ll ret1 = (n * (n - 1) * (n + 1) / 6) % mod;
    ll ret2 = (m * (m - 1) * (m + 1) / 6) % mod;
    ll ret = (m * m * ret1 + n * n * ret2) % mod;
    cout << nCk(n * m - 2, k - 2) * ret % mod << endl;
    return 0;
}