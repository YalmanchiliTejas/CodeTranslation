#include "iostream"

int main(){
    char s[3];
    std::cin >> s;
    if (s[0]==s[1] && s[1]==s[2]){
        std::cout << "No";
    }else{
        std::cout << "Yes";
    }
}