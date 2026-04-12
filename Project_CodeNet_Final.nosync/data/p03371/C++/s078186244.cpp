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


int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans1 = a * x + b * y;
    ll ans2 = 0;
    if (x <= y) ans2 = 2 * c * x + b * (y - x);
    else ans2 = 2 * c * y + a * (x - y);
    ll ans3 = 2 * c * max(x, y);

    cout << min({ans1, ans2, ans3}) << endl;

    return 0;
}
