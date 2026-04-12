#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <iomanip>
 
 
int main()
{
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    int mi = INT32_MAX;

    for(int i=0; i<=std::max(x, y); i++)
    {
        mi =  std::min(mi, 2 * c * i + a * std::max(x-i, 0) + b * std::max(y-i, 0));
    }

    std::cout << mi << std::endl;

    return 0;
}
