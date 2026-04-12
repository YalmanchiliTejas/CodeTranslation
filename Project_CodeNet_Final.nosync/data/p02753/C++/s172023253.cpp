#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>



int main()
{
    std::string S;
    std::cin >>S;
    if(S[0]==S[1] && S[2]==S[0]){
        std::cout << "No" << std::endl;
    }else{
        std::cout << "Yes" << std::endl;
    }
    return 0;
}