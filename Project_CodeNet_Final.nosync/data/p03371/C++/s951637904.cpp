// C - Half and Half
// https://beta.atcoder.jp/contests/abc095/tasks/arc096_a
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;


long long solve(int A, int B, int C, int X, int Y);

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long ans = solve(A, B, C, X, Y);
    cout << ans << endl;
}


long long solve(int A, int B, int C, int X, int Y) {
    if (A + B <= 2 * C)
        return A * X + B * Y;

    int m = min(X, Y);
    long long ans = 2 * m * C;

    Y -= m;
    if (2 * C < B)
        ans += 2 * C * Y;
    else
        ans += B * Y;

    X -= m;
    if (2 * C < A)
        ans += 2 * C * X;
    else
        ans += A * X;

    return ans;
}
