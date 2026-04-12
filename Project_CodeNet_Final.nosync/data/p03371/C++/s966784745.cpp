#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int g = min(2*c, a+b);

    int ans = 0;
    ans += min(x, y)*g;
    if (x>y) ans += (x-y)*min(a, g);
    if (y>x) ans += (y-x)*min(b, g);

    cout << ans << endl;
}
