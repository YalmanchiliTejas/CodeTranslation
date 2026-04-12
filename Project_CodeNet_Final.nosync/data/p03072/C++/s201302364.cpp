#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> H(N);
    std::vector<int> HM(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    HM[0] = H[0];
    for (int i = 1; i < N; i++) {
        HM[i] = std::max(H[i], HM[i-1]);
    }

    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (H[i] >= HM[i]) ans++;
    }

    std::cout << ans << std::endl;

    return 0;
}