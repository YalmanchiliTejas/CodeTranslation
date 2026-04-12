#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>


int main() {

    int A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;

    int m = std::min(X, Y);
    long sum = 0;
    if ((A + B) >= 2 * C) {
        sum += 2 * C * m;

        if (A >= 2 * C) {
            sum += 2 * C * (X - m);
        } else {
            sum += A * (X - m);
        }

        if (B >= 2 * C) {
            sum += 2 * C * (Y - m);
        } else {
            sum += B * (Y - m);
        }

    } else {
        sum += A * X;
        sum += B * Y;
    }

    std::cout << sum << "\n";

    return 0;
}
