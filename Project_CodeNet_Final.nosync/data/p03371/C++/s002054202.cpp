#include <bits/stdc++.h>
using namespace std;
int main() {
    #ifdef DEBUG
    std::ifstream in("/home/share/inputf.in");
    std::cin.rdbuf(in.rdbuf());
    #endif
    int A, B, C, X, Y, ans;
    cin >> A >> B >> C >> X >> Y;
    ans = 0;
    int s = min(X, Y);
    int t = min(A + B, 2 * C);
    X -= s;
    Y -= s;
    ans += s * t;
    if(Y == 0) {
        if(A >= 2 * C) {
            ans += 2 * C * X;
        } else {
            ans += A * X;
        }
    } else {
        if(B >= 2 * C) {
            ans += 2 * C * Y;
        } else {
            ans += B * Y;
        }
    }
    cout << ans << endl;
    return 0;
}