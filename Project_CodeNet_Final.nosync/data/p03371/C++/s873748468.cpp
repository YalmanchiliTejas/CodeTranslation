#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    // 別々に買うパターン
    int p1 = A * X + B * Y;
    // 個数が少なくなるようにセット（AB）を多くするパターン
    int p2 = 0;
    if (X > Y) {
        p2 = C * Y * 2 + A * (X - Y);
    } else if (X < Y) {
        p2 = C * X * 2 + B * (Y - X);
    } else {
        p2 = C * (X + Y);
    }
    // 個数を超過してもセットで買うパターン
    int p3 = C * max(X, Y) * 2;

    int ans = min(min(p1, p2), p3);
    cout << ans << endl;
}