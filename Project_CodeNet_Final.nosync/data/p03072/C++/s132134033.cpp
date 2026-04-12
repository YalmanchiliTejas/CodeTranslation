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
    // std::cout << std::fixed << std::setprecision(10);
    
    int n; std::cin >> n;
    std::vector<int> h(n);
    for(int i=0; i<n; i++) std::cin >> h[i];
    int cnt = 1, highest = h[0];
    for(int i=1; i<n; i++)
    {
        if(h[i] == std::max(h[i], highest))
        {
            cnt++;
            highest = h[i];
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}