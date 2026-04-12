#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }
    int sum = 1;
    int maxv = h[0];
    for(int i = 1; i < n; i++){
        if(maxv <= h[i] && h[i] >= h[i-1]){
            sum++;
        }
        maxv = std::max(maxv, h[i]);
    }
    std::cout << sum;
    return 0;
}
