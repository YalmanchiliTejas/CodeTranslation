/*
  A - AtCoder *** Contest
  Contest 049
  Rakesh Kumar --> 03/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    char c = ' ';
    std::cin >> c;
    if (c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u')
        std::cout << "vowel" << std::endl;
    else
        std::cout << "consonant" << std::endl;

    return 0;
}
