#include <iostream>
#include <set>
int main () {
    std::set<char> vowelSet = {'a', 'i', 'u', 'e', 'o'};

    char c;

    std::cin >> c;
    std::size_t n = vowelSet.count(c);

    if(n==1){
       std::cout << "vowel" << std::endl;
    }else{
       std::cout << "consonant" << std::endl;
    }
}