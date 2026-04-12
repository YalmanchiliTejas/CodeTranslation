#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rmin(r, x) r = min(r, x);
#define rmax(r, x) r = max(r, x);
#define ends ' '
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

int main(void) {
    fastio;
    int n;  cin >> n;
    ll ans = 0, sum = 0;
    for(int i = 1; i <= n; ++i) {
        ll x;   cin >> x;
        ans += sum * x;
        sum += x;
        ans %= mod;
        sum %= mod;
    }
    cout << ans;
    return 0;
}
