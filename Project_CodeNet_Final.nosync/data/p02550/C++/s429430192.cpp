#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rmin(r, x) r = min(r, x)
#define rmax(r, x) r = max(r, x)
#define ends ' '
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxm = 1e5 + 10;

ll n, m, x, s[maxm];
int in[maxm];

int main(void) {
    fastio;
    cin >> n >> x >> m;
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(in[x]) {
            int j = i - in[x];
            ans += (n - i + 1) / j * (s[i - 1] - s[in[x] - 1]);
            ans += s[in[x] + (n - i + 1) % j - 1] - s[in[x] - 1];
            cout << ans;
            return 0;
        }
        in[x] = i;
        ans += x;
        s[i] = s[i - 1] + x;
        x = x * x % m;
    }
    cout << ans;
    return 0;
}
