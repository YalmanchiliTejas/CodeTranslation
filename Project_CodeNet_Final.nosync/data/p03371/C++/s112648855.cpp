#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int a, b, c, x, y, ans = 0;
    cin >> a >> b >> c >> x >> y;
    if(a + b < 2 * c) {
        ans = a * x + b * y;
    } else {
        int temp = min(x, y);
        ans = 2 * c * temp;
        x -= temp;
        y -= temp;
        ans += ((a < 2 * c)? a : 2 * c) * x;
        ans += ((b < 2 * c)? b : 2 * c) * y;
        
    }
    cout << ans << endl;
}