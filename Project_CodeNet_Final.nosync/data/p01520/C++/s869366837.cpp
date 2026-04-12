#include <iostream>
#include <cmath>

int main() {
    int n, t, e, p;
    
    std::cin >> n >> t >> e;
    for(int i = 0; i < n; ++i) {
        std::cin >> p;
        
        if(std::abs(t - t / p * p) <= e || std::abs(t - (t / p + 1) * p) <= e) {
            std::cout << i + 1 << std::endl;
            
            return 0;
        }
    }
    
    std::cout << -1 << std::endl;

    return 0;
}