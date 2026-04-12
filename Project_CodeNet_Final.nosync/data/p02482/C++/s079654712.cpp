#include <iostream>

int main(void) {
    int firstNum;
    int secondNum;
    std::string func = "==";
    
    std::cin >> firstNum;
    std::cin >> secondNum;
    
    if(firstNum < secondNum){
        func="<";
    }else if(firstNum > secondNum){
        func=">";
    }
    
    std::cout << "a " + func + " b"  << std::endl;
    
    return 0;
}