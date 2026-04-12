#if 1
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

#if DEBUG_ON
    freopen("input", "r", stdin);
#endif

    std::string str;
    std::cin >> str;
    if (str[0] == str[1] && str[1] == str[2]) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
    }
    return 0;
}
#endif