#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if (A + B < C * 2) {
        ans += A * X + B * Y;
    } else {
        if (X < Y) {
            ans += C * 2 * X;
            Y -= X;
            if (B < C * 2) {
                ans += B * Y;
            } else {
                ans += C * 2 * Y;
            }
        } else {
            ans += C * 2 * Y;
            X -= Y;
            if (A < C * 2) {
                ans += A * X;
            } else {
                ans += C * 2 * X;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
