#include <bits/stdc++.h>

int main() {
    int A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;

    const int cost1 = A * X + B * Y;

    int cost2 = 0;
    if (X < Y) {
        cost2 = C * 2 * X;
        cost2 += (Y - X) * B;
    } else {
        cost2 = C * 2 * Y;
        cost2 += (X - Y) * A;
    }

    const int cost3 = std::max(X, Y) * 2 * C;

    std::cout << std::min({cost1, cost2, cost3}) << std::endl;

    return 0;
}
