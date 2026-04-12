#include <iostream>
#include <list>
int main () {
    std::list<char> vowelList;
    vowelList.push_back('a');
    vowelList.push_back('i');
    vowelList.push_back('u');
    vowelList.push_back('e');
    vowelList.push_back('o');

    char c;

    std::cin >> c;

    for(auto x : vowelList) {
        if(c == x) {
            std::cout << "vowel" << std::endl;
            return 0;
        }
    }
    std::cout << "consonant" << std::endl;

}