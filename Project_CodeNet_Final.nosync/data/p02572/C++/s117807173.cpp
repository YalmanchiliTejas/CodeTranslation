#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll a[200010], acc[200010];
ll s, ans;

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) acc[i+1] = acc[i] + a[i];

    rep(i, n) {
        ll tmp = acc[n] - acc[i+1];
        tmp %= MOD;
        ans += tmp * a[i];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
