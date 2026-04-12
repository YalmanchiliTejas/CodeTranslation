#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1e9;
    for (int i = 0; i < 202020; i++) {
        int A = x - i / 2;
        int B = y - i / 2;
        if (A < 0) A = 0;
        if (B < 0) B = 0;
        int money = i * c + A * a + B * b;
        ans = min(ans, money);
    }
    cout << ans << endl;
}