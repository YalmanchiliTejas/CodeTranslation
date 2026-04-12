#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    int ans = 1;
    int max = h[0];
    for (int i = 1; i < n; i++) {
        if (max <= h[i]) {
            ans++;
            max = h[i];
        }
    }

    std::cout << ans << std::endl;
}
