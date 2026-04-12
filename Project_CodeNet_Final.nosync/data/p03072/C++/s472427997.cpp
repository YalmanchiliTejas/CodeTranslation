#include <iostream>

int main()
{
    int N, H[101];
    int ans = 1;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> H[i];
    }
    for (int j = 1; j < N; j++) {
        for (int k = 0; k < j; k++) {
            if (H[k] > H[j]) {
                break;
            }
            if (k == j - 1) {
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;

}