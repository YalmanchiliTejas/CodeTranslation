#include <iostream>
#include <algorithm>

int main() {
    int A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;

    int min_price = A * X + B * Y;
    for (int c = 0; c <= std::max(X, Y) * 2; c += 2) {
        int a = std::max(X - c / 2, 0);
        int b = std::max(Y - c / 2, 0);
        min_price = std::min(A * a + B * b + C * c, min_price);
    }
    std::cout << min_price << std::endl;
}
