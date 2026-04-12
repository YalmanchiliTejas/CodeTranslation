#include <bits/stdc++.h>

int main() {
    int h, w;
    std::cin >> h >> w;
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < w; j++) if (s[j] == '#') cnt++;
    }
    std::cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << std::endl;

    return 0;
}