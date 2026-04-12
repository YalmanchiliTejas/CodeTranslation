#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define repd(i, a, b) for (int i = a; i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    const int m = 1e9 + 7;
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<ll> sum(n + 1, 0);
    repd(i, n - 1, 1) sum[i] = (sum[i + 1] + a[i + 1]) % m;
    ll ans = 0;
    rep(i, 1, n + 1) ans = (ans + a[i] * sum[i] % m) % m;
    cout << ans << endl;
}
