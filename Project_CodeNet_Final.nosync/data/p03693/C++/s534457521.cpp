/*
  Contest 064
  A - RGB Cards
  Rakesh Kumar --> 31/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    for (int i = 0; i < 3; ++i) {
        int a = 0;
        std::cin >> a;
        n = (n * 10) + a;
    }
    std::cout << (n % 4 ? "NO" : "YES") << std::endl;

    return 0;
}
