#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

int main(void){
    long n, x, m;
    std::cin >> n >> x >> m;
    std::vector<int> v(m, -1);
    long x1 = x, from = -1, to = -1, tmpcnt = 0;
    for(int i = 0; i <= m; ++i){
        if(i == n){
            std::cout << tmpcnt <<std::endl;
            return 0;
        }
        tmpcnt += x1;
        if(-1 == v[x1]) v[x1] = i + 1;
        else{
            from = v[x1];
            to = i + 1;
            break;
        }
        x1 = (x1 * x1) % m;
    }
    long cnt = 0;
    x1 = x;
    for(long i = 1; i < from; ++i){
        cnt += x1;
        x1 = (x1 * x1) % m;
    }
    long sum_loop = 0;
    for(long i = from; i < to; ++i){
        sum_loop += x1;
        x1 = (x1 * x1) % m;
    }
    cnt += sum_loop * ((n - from + 1) / (to - from));
    long tmp = from - 1 + ((n - from + 1) / (to - from)) * (to - from) + 1;
    for(long i = tmp; i <= n; ++i){
        cnt += x1;
        x1 = (x1 * x1) % m;
    }
    std::cout << cnt << std::endl;

    return 0;
}