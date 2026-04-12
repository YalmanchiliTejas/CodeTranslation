#include <iostream>

int main(){
    char ch;
    std::cin >> ch;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') std::cout << "vowel";
    else std::cout << "consonant";
}