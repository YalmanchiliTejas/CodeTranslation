#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll A, B, C, X, Y;
    ll ans = 0;
    ll m;

    cin >> A >> B >> C >> X >> Y;

    m = min({X, Y});
    if (A+B < 2 * C) {
        ans += m * (A+B);
        X -= m;
        Y -= m;
    } else {
        ans += m * 2 * C;
        X -= m;
        Y -= m;
    }

    if (X == 0) {
        if (B < 2*C) {
            ans += Y * B;
        } else {
            ans += Y * 2 * C;
        }
    } else {
        if (A < 2*C) {
            ans += X * A;
        } else {
            ans += X * 2 * C;
        }
    }

    cout << ans << endl;
}
