#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void solve() {
    int a, b, c, x, y; scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    int ans = 0;
    int k = min(x, y);
    if (2*c < a+b) {
        ans += k*2*c;
    } else {
        ans += k*a+k*b;
    }
    x -= k; y -= k;
    if (x > y) {
        if (2*c < a) {
            ans += x*2*c;
        } else {
            ans += x*a;
        }
    } else {
        if (2*c < b) {
            ans += y*2*c;
        } else {
            ans += y*b;
        }
    }
    printf("%d", ans);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}