#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> X(N);
    for (int i = 0; i < N; ++i) std::cin >> X[i];
    
    std::vector<std::pair<int, int>> Y(N);
    for (int i = 0; i < N; ++i) Y[i] = std::make_pair(X[i], i);
    sort(Y.begin(), Y.end());
    std::vector<int> Z(N);
    for (int i = 0; i < N; ++i) Z[Y[i].second] = i;
    
    for (int i = 0; i < N; ++i) {
        if (Z[i] < N / 2) std::cout << Y[N / 2].first << std::endl;
        else std::cout << Y[N / 2 - 1].first << std::endl;
    }
    return 0;
}
