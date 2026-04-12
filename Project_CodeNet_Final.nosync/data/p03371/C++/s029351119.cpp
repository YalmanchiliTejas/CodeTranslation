#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll yen = A * X + B * Y;
    ll m = yen;
    if (X < Y) {
        for (int i = 0; i < X; ++i) {
            yen = yen - A - B + 2 * C;
            m = min(m, yen);
        }
        for (int i = 0; i < Y-X; ++i) {
            yen = yen - B + 2 * C;
            m = min(m, yen);
        }
    } else {
        for (int i = 0; i < Y; ++i) {
            yen = yen - A - B + 2 * C;
            m = min(m, yen);
        }
        for (int i = 0; i < X-Y; ++i) {
            yen = yen - A + 2 * C;
            m = min(m, yen);
        }
    }
    cout << m << endl;
}
