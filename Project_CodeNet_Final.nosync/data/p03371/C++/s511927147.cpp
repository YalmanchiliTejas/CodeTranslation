#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    // A, B バラ買いパターン
    int n = a * x + b * y;

    // A, B のどちらか必要な量を超えるパターン
    int m = 2 * c * max(x, y);

    // 必要最小限の Cセットを買い、足りない分はバラ買いパターン
    int p = x < y ? b : a;
    int l = 2 * c * min(x, y) + p * abs(x - y);

    // 上記のうちで1番安いの
    int ans = min(n, min(m, l));
    cout << ans << endl;
}