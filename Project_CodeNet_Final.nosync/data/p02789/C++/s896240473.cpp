#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int main()
{
    long N,M;
    std::cin >> N >> M;
    if(N==M){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}