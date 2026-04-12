/*
  A - Restaurant
  Contest 055
  Rakesh Kumar --> 16/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;

    std::cout << (n * 800) - ((n / 15) * 200) << std::endl;

    return 0;
}
