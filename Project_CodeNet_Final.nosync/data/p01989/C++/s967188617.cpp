#include <bits/stdc++.h>
int main()
{
    std::string s;
    std::cin >> s;
    const int N = s.size();
    std::vector<std::vector<int>> to(N);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 3; j++) {
            const int num = std::stoi(s.substr(i, j));
            if (num > 255) { continue; }
            if (num == 0) {
                if (j > 1) { continue; }
            } else {
                if (s[i] == '0') { continue; }
            }
            to[i].push_back(i + j);
        }
    }
    std::vector<std::vector<int>> memo(N + 1, std::vector<int>(5, -1));
    auto rec = [&, N](auto&& self, const int i, const int j) {
        if (j == 4) { return (i == N ? 1 : 0); }
        if (i >= N) { return 0; }
        if (memo[i][j] != -1) { return memo[i][j]; }
        int ans = 0;
        for (const int n : to[i]) { ans += self(self, n, j + 1); }
        return memo[i][j] = ans;
    };
    const int ans = rec(rec, 0, 0);
    std::cout << ans << std::endl;
    return 0;
}

