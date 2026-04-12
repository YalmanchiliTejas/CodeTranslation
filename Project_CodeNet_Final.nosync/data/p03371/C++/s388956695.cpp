#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

int main(){
    int a, b, c, x, y;
    std::cin>>a>>b>>c>>x>>y;

    long long res = 9000000000;
    for(int k = 0;k <= 2 * std::max(x, y);k++){
        long long m = a * (x >= k ? x - k : 0) +
            b * (y >= k ? y - k : 0) + c * 2 * k;
        if(m < res){
            res = m;
        }

    }
    std::cout<<res<<std::endl;
    return 0;
}