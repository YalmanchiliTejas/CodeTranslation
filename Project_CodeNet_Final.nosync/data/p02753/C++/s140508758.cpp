#include <iostream>
#include <set>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::set<char> ss;
    
    for(int i = 0; i < 3; i++) {
        ss.insert(s[i]);
    }

    if(ss.size() != 1) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
