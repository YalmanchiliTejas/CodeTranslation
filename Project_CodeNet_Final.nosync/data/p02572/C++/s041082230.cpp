#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define SZ(x) (int)((x).size())
#define xx first
#define yy second
#define pii pair<int, int>

const int N = 2e5 + 1;
const ll mod = 1e9 + 7;

int a[N];
ll prfx[N + 1];

void solve() {
    int n;
    cin >> n;
    prfx[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prfx[i + 1] = prfx[i] + a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a = prfx[i + 1] - prfx[i];
        ll b = prfx[n] - prfx[i + 1];
        ans += ((a % mod) * (b % mod)) % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
