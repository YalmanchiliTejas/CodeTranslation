#include <iostream>

int main() {
    int n, h[100];
    std::cin >> n;
    for (int i = 0; (i < n); ++i) {
        std::cin >> h[i];
    }
    int sum = 1;
    for (int i = 1; (i < n); ++i) {
        bool ok = true;
        for (int j = 0; (j <= i - 1); ++j) {
            if (h[j] > h[i]) {
                ok = false;
            }
        }
        if (ok) sum++;
    }
    std::cout << sum << std::endl;
    return 0;
}
