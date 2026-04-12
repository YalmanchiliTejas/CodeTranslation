#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair <ll, ll> pi;

ll a, b, c, d, x, y, ans;

int main() {
    cin >> a >> b >> c >> x >> y;
    d = min(a + b, 2 * c);
    if (x > y) {
        ans += (x - y) * min(2 * c, a);
        x = y;
    } else {
        ans += (y - x) * min(2 * c, b);
        y = x;
    }
    ans += d * x;
    cout << ans << endl;
}