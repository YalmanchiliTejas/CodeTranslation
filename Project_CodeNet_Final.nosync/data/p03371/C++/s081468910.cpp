#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    int ans = 0;
    if (a + b <= 2 * c) {
        ans = x * a + y * b;
    }
    else { // 2 * c < a + b
        
        if (x <= y) {
            ans += 2 * c * x;
            y -= x;
            ans += y * min(b, 2 * c);
        }
        else {
            ans += 2 * c * y;
            x -= y;
            ans += x * min(a, 2 * c);
        }

    }

    cout << ans << endl;
    return 0;
}