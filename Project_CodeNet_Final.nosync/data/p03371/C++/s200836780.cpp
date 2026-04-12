#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = INT_MAX;
    
    for (int i = 0; i <= max(x, y); i++) {
        ans = min(ans, a * max(x - i, 0) + b * max(y - i, 0) + c * i * 2);
    }
    
    cout << ans << endl;
    return 0;
}