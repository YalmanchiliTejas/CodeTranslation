#include <iostream>

bool is_vowel(char c)
{
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':   return true;
        default:    return false;
    }
}

int main(void)
{
    char c;
    std::cin >> c;
    bool vowel = is_vowel(c);
    std::cout << (vowel ? "vowel" : "consonant") << std::endl;
    return 0;
}
