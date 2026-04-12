#include <bits/stdc++.h>

int main()
{
    std::string s;
    std::cin >> s;
    for (int i = 1; i < 3; i++) {
        if (s[i-1] != s[i]) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;

    return 0;
}
