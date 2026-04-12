#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
 
int main()
{
    long long int x, y, z, ans = 0;

    std::cin >> x >> y >> z;

    x -= z;
    while(x >= y + z){
        x -= y + z;
        ans++;
    }

    std::cout << ans;

    return 0;
}