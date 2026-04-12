#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

int main(){
    int x, y, z;
    std::cin>>x>>y>>z;

    std::cout<<(x - z) / (y + z)<<std::endl;
    return 0;
}