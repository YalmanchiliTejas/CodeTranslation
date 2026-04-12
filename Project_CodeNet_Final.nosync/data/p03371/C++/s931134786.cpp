#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = INT_MAX;
    for(ll i = 0; i <= 2 * (x + y); i += 2) {
        ll p1 = i / 2;
        ll p2 = i / 2;
        ll tmp = i * c;
        tmp += max(0LL, x - p1) * a;
        tmp += max(0LL, y - p2) * b;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}