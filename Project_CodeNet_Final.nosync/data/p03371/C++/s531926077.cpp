#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = c * 2 * (x + y);
    for (int i = 0; i / 2 <= max(x, y); i += 2) {
        int price = c * i + a * max(0, x - i / 2) + b * max(0, y - i / 2);
        ans = price < ans ? price : ans;
    }

    cout << ans << endl;
}