#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::cin.tie(0);
     std::ios_base::sync_with_stdio(false);
    
    int N;
    std::cin >> N;
    std::vector<int> v(N), xs(N);
    
    for (int i{}, tmp; i < N; ++i) {
        std::cin >> tmp;
        xs[i] = tmp;
        v[i] = tmp;
    };
    std::sort( begin(v), end(v) );
    
    for (int i{}; i < N; ++i) {
        if (xs[i] <= v[N/2-1]) std::cout << v[N/2] << "\n";
        else std::cout << v[N/2-1] << "\n";
    };
}