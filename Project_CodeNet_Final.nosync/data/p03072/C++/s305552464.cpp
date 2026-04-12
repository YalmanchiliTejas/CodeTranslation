#include <iostream>

int
main(int argc, char** argv) {
    int N;
    std::cin >> N;

    int H1;
    std::cin >> H1;
    int maxH = H1;
    int ans = 1;
    for (int i = 1; i < N; i++) {
       int H;
       std::cin >> H;
       if (maxH <= H) ans++;
       maxH = std::max(maxH, H);
    }

    std::printf("%d\n", ans);
    return 0;
}