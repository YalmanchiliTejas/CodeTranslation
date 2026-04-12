#include <bits/stdc++.h>

int main() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;
    std::printf("%d\n", (X - Y - 2 *Z) / (Y + Z) + 1);

    return 0;
}
