#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;
using ll = long long;

// inf
constexpr ll infl = 1LL << 60;
constexpr int inf = 1 << 30;

int main() {
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ans = 0;

    if (2 * C < (A + B)) {
        ans += 2 * C * min(X, Y);
        if (X < Y) {
            ans += min(2 * C, B) * (Y - X);
        }
        else if (X > Y) {
            ans += min(2 * C, A) * (X - Y);
        }
    }
    else {
        ans = A * X + B * Y;
    }
    cout << ans << endl;
}