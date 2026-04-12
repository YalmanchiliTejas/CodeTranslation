#include <iostream>
#include <string>
#include <functional>
int main() {
std::string S;
std::cin >> S;
std::string::size_type pos=S.find("AC");
if(pos <6)
std::cout << "Yes" << std::endl;
else
std::cout << "No" << std::endl;
}