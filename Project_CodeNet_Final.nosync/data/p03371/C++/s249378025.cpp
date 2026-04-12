#include <iostream>


int main() {
    long a, b, c, x, y;

    std::cin >> a >> b >> c >> x >> y;

    long maxI = std::max(x, y);
    long minPrice = NULL;

    for (long i = 0; i < maxI+1; ++i) {
        long price = i*2*c + std::max((long)0, x-i) *a + std::max((long)0, y-i)*b;

        minPrice = minPrice == NULL or minPrice > price ? price : minPrice;
    }

    std::cout << minPrice << std::endl;

    return 0;
}