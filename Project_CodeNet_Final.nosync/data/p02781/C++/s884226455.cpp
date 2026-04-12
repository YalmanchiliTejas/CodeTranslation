#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int d[110][4][2];

int g(char ch)
{
    return atoi(&ch);
}

int main()
{
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;

    rep(i, s.size())
        d[i][0][0] = 1;

    d[0][1][1] = 1;
    d[0][1][0] = g(s[0]) - 1;

    for (int i = 1; i < s.size(); ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            d[i][j][0] = 9 * d[i - 1][j - 1][0] + d[i - 1][j][0];
            if (g(s[i]) > 0)
            {
                d[i][j][0] += (g(s[i]) - 1) * d[i - 1][j - 1][1] + d[i - 1][j][1];
            }
            d[i][j][1] = g(s[i]) ? d[i - 1][j - 1][1] : d[i - 1][j][1];
        }
    }

    std::cerr << d[s.size() - 1][k][1] << std::endl;

    std::cout
        << d[s.size() - 1][k][0] + d[s.size() - 1][k][1] << std::endl;
    return 0;
}