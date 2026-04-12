#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        std::cin >> k;
        auto position = std::lower_bound(A.begin(), A.end(), k);
        std::cout << std::distance(A.begin(), position) << std::endl;
    }
}

