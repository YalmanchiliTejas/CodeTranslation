#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    int ans = 1;

    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    for (int i = 1; i < N; ++i) {
        bool f = true;
        for (int j = 0; j < i; ++j) {
            if (H[i] < H[j]) f = false;
        }
        if (f) ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}

