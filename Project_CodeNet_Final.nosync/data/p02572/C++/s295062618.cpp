#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
int main() {
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll x = 0;
    for (int i = 1; i <= n; i++) {
        x = (x + a[i]) % mod;
    }
    x = x * x % mod;
    ll y = 0;
    for (int i = 1; i <= n; i++) {
        y = (y + a[i] * a[i] % mod) % mod;
    }
    ll ret = x - y;
    if (ret < 0) {
        ret += mod;
    }
    if (ret % 2) {
        ret = ((ret + mod) / 2) % mod;
    }
    else {
        ret /= 2;
    }
    cout << ret << endl;
    return 0;
}