#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cassert>
#include <utility>
#include <vector>


int main(void){
    std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); 
    std::cout << std::fixed << std::setprecision(16);
    int n; std::cin >> n;
    if(n >= 30) std::cout << "Yes\n"; else std::cout << "No\n";
    
    return 0;
}