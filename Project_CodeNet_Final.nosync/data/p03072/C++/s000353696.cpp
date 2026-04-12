#include <iostream>
#include <vector>

int main() {
    int N, temp, ans=0;
    std::vector<int> H;
    std::cin >> N;
    
    for (int i=0; i<N; i++) {
        std::cin >> temp;
        H.push_back(temp); 
    }
    
    int highest = H.front();
    
    for (auto &&e : H) {
        if (e >= highest) {
            ans++;
            highest = e;
        }
    }
    
    std::cout << ans << std::endl;
}