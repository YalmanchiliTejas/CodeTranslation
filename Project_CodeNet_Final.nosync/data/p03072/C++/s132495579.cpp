#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    int n,ans = 1;
    std::cin >> n;

    std::vector<int> h(n);

    for (int i = 0; i < n; i++)
        std::cin >> h[i];

    int max = h[0];

    for(int i=1;i<n;i++){
        if(h[i] >= max){
            ans++;
            max = h[i];
        }
    }

    std::cout << ans << std::endl;
    return 0;
}