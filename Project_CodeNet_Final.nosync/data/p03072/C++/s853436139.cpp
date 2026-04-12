#include <iostream>
#include <vector>

int main() {
    int n, ans=0;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto &v : vec) std::cin >> v;
    for (int i=0; i<n; ++i) {
        bool flag = true;
        for (int j=0; j<i; ++j) {
            if (vec[j] > vec[i]) flag = false;
        }
        if (flag) ++ans;
    }
    std::cout << ans << '\n';
    return 0;
}