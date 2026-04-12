#include <iostream>
using namespace std;
int main(void){
    char str[4];
    
    std::cin >> str;
    
    if(str[0] == str[1] && str[1]==str[2]){
        std::cout << "No" << endl;
    }else{
        std::cout << "Yes" << endl;
    }
    return 0;    
}
