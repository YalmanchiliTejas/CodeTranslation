/*
  Contest 078
  B - ISU
  Rakesh Kumar --> 13/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int x = 0, y = 0, z = 0;
    std::cin >> x >> y >> z;
    int seats = x / (y + z);
    if (((seats * y) + ((seats + 1) * z)) > x)
        --seats;
    std::cout << seats << std::endl;

    return 0;
}
