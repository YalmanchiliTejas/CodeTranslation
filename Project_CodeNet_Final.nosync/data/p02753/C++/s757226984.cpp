#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int count_a = 0, count_b = 0;
    for (char c : s) {
        if (c == 'A') ++count_a;
        else ++count_b;
    }
    std::cout << (count_a > 0 && count_b > 0 ? "Yes" : "No") << std::endl;
    return 0;
}