#include <iostream>

int main() {

    char input;
    scanf("%c", &input);
    if (input == 'a' || input == 'i' || input == 'u' || input == 'e' || input == 'o') {
        std::cout << "vowel" << std::endl;

    } else {
        std::cout << "consonant" << std::endl;
    }
    return 0;
}