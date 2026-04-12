#include <iostream>

int main() {
    int x = 0;
    int y = 0;
    
    int n = 0;
    std::cin >> n;
    
    for(int i = 1; i <= n; i++) {
        x += 800;
        if(i%15==0) {
            y += 200;
        }
    }
    
    std::cout << x-y << std::endl;
}