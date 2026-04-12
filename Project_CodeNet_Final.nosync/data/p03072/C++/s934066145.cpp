#include <bits/stdc++.h>

int main() {
    int N, H;
    int max = 0, cnt = 0;

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> H;
        if (i == 0) {
            ++cnt;
            max = H;
        } else {
            if (max <= H) {
                ++cnt;
                max = H;
            }
        }
    }

    std::printf("%d\n", cnt);

    return 0;
}
