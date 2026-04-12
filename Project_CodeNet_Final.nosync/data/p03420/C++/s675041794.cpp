#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

ll n, k;

int main() {
    cin >> n >> k;
    ll ans = 0;
    for (ll b = k+1; b <= n; b++) {
        ll t = b-k;
        ll c = n/b;
        ans += c*t;
        ll x = c*b+k;
        if (x <= n) {
            ans += n-x+1;
        }
    }
    if (k == 0) ans -= n;
    cout << ans << endl;
}






























