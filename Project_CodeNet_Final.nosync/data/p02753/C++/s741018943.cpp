#include <iostream>

int main()
{
    char s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    if (s1 == s2 && s2 == s3) {
        std::cout << "No";
    } else {
        std::cout << "Yes";
    }

    return 0;
}