#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    if (A + B < C*2) {
        ans += min(X, Y) * (A + B);
    } else {
        ans += min(X, Y) * C*2;
    }

    int over_c, over_n;
    if (X > Y) {
        if (A < C*2) {
            ans += (X - Y) * A;
        } else {
            ans += (X - Y) * C*2;
        }
    } else {
        if (B < C*2) {
            ans += (Y - X) * B;
        } else {
            ans += (Y - X) * C*2;
        }
    }

    cout << ans << endl;

    return 0;
}
