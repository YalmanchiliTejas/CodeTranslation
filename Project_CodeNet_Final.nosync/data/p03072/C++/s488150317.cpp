#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> H(N);
    for (auto& h : H) std::cin >> h;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        bool judge = true;
        for (int j = 0; j < i; ++j) {
            if (H[j] > H[i]) judge = false;
        }
        if (judge) ++ans;
    }

    std::cout << ans << std::endl;
    return 0;
}
