#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    //printf("%d %d %d %d %d\n", A, B, C, X, Y);
    int mi = 1 << 30;
    int res = 0;
    if (A + B > 2 * C && X > 0 && Y > 0) {
        int R = min(X,Y);
        res = C * 2 * R;
        X -= R;
        Y -= R;
    }
    if (A < 2 * C) {
        res += A * X;
    } else {
        res += (2 * C) * X;
    }
    if (B < 2 * C) {
        res += B * Y;
    } else {
        res += (2 * C) * Y;
    }

    cout << res << endl;
}