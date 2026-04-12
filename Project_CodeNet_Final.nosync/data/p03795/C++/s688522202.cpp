#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

int main(){
    int n;
    std::cin>>n;

    int k = n / 15;
    std::cout<<(800 * n - 200 * k)<<std::endl;
    return 0;
}