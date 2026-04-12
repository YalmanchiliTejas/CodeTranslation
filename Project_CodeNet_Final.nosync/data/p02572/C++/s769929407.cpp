#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define double long double
using namespace std;
const ll inf = 1000000000000000000;

const ll mod = 1000000007;
ll n, x, sum, ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> x;
    sum += x;
    for (ll i = 2; i <= n; ++i) {
        cin >> x;
        ans += ((sum * x) % mod);
        ans %= mod;
        sum += x;
        sum %= mod;
    }
    cout << ans;
    return 0;
}
