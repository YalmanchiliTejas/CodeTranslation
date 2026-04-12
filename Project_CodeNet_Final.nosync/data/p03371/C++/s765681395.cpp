#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 1; i <= (n); ++i)

int main() {
    int a, b, c, x, y;
    int ans = 1000000000;
    cin >> a >> b >> c >> x >> y;
    for (int i = 0; i <= pow(10, 5); ++i) {
        int tmp = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b;
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}