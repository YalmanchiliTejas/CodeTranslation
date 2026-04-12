#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    int cnt[n][26] = {0};
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        for (size_t j = 0; j < s.size(); ++j) {
            const int c = s[j] - 'a';
            cnt[i][c] += 1;
        }
    }

    
    std::ostringstream oss;
    for (int i = 0; i < 26; ++i) {
        const char c = 'a' + i;
        int min = INT32_MAX;
        for (int j = 0; j < n; ++j) {
            min = std::min(min, cnt[j][i]);
        }

        for (int j = 0; j < min; ++j) {
            oss << c;
        }
    }

    std::cout << oss.str() << std::endl;

    return 0;
}
