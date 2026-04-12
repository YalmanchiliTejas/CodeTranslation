#include<iostream>

int main(){
    int x; std::cin >> x;
    std::string s="NO";
    if(x == 7 || x == 5 || x == 3) s="YES";
    std::cout << s << std::endl;
    return 0;
}