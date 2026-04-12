#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int count_A = 0;

    for (auto c : s) {
        if (c == 'A') count_A++;
    }

    std::cout << (count_A == 0 || count_A == 3 ? "No" : "Yes");


    return 0;
}