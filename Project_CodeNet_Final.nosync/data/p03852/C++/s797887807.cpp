#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
        char lower_input;
        std::cin >> lower_input;

        if (lower_input == 'a'
        || lower_input == 'e'
        || lower_input == 'i'
        || lower_input == 'o'
        || lower_input == 'u') {
                std::cout << "vowel" << std::endl;
        } else {
                std::cout << "consonant" << std::endl;
        }

        return 0;
}