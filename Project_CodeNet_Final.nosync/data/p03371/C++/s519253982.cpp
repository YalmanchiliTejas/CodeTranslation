#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = a*x + b*y;
    for (int i = 0; i <= max(x, y); i++) {
        ans = min(ans, 2*c*i+max(x-i, 0)*a+max(y-i, 0)*b);
    }
    cout << ans << endl;
    return 0;
}
