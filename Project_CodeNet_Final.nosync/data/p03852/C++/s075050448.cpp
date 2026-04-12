#include<iostream>

char c;

int main(){
    std::cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') std::cout << "vowel";
    else std::cout << "consonant";

    return 0;
}