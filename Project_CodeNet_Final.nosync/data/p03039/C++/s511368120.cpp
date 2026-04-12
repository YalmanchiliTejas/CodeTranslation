#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

ll inv(ll a) {
    ll b = mod - 2, c = 1;
    while (b) {
        if (b % 2) c = c * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    ll n, m, k, z = 1;
    cin >> n >> m >> k;
    for (ll i = n * m - k + 1; i <= n * m - 2; i++) z = z * i % mod;
    for (ll i = 1; i <= k - 2; i++) z = z * inv(i) % mod;
    cout << z * ((n + 1) * n % mod * (n - 1) % mod * 166666668 * m % mod * m % mod + (m + 1) * m % mod * (m - 1) % mod * 166666668 * n % mod * n % mod) % mod;
}
