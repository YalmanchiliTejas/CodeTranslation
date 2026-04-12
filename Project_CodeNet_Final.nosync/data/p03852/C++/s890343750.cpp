#include<iostream>

int main() {
    char a;
    std::cin >> a;
    if(a == 'a' || a ==  'e' || a == 'i' || a == 'o' || a == 'u')
        std::cout << "vowel" << std::endl;
    else
        std::cout << "consonant" << std::endl;
}