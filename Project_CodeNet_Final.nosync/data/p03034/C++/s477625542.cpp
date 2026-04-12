#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> s(N);
    for (int i = 0; i < N; i++)
        std::cin >> s[i];

    long long ans = 0;
    for (int c = 1; c < N; c++) {
        long long res = 0;
        int i = 0, j = N - 1;
        if ((N - 1) % c) {
            while (j > c) {
                res += s[i] + s[j];
                ans = std::max(ans, res);
                i += c;
                j -= c;
            }
        }
        else {
            while (i < j) {
                res += s[i] + s[j];
                ans = std::max(ans, res);
                i += c;
                j -= c;
            }
        }
    }
    std::cout << ans << "\n";
}