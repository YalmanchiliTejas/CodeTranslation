#include <bits/stdc++.h>
using namespace std;

long A, B, C, X, Y, ans;

int main(void) {

    cin >> A >> B >> C >> X >> Y;

    ans += min(A+B, C*2) * min(X, Y);

    long tmp = min(X,Y);
    X -= tmp; Y -= tmp;

    if (X > 0) {
        ans += min(A, C*2) * X;
    }

    if (Y > 0) {
        ans += min(B, C*2) * Y;
    }

    cout << ans << endl;

    return 0;

}