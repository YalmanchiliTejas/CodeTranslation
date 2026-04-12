#include <iostream>
#include <set>
#include <string>
#include <vector>

int main(void){
    std::string r,g,b;
    std::cin >> r >> g >> b;

    std::string s = r + g + b;
    int abc = stoi(s);

    std::cout << (abc % 4 == 0 ? "YES" : "NO");
    return 0;
}
