#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>

template <typename T>
void read(T& x)
{
    x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar());
    for (; isdigit(c); x = x * 10 + (c ^ 48), c = getchar());
}

unsigned long long get2(std::string s)
{
    while (s[0] == '0')
        s = s.substr(1, s.length() - 1);
    unsigned long long x = s[0] - '0', ans = 0;
    if (x == 0)
        return 0;
    if (s.length() >= 2)
        ans += 1ull * (x - 1ull) * (s.length() - 1ull) * 9ull;
    if (s.length() >= 3)
        ans += 1ull * (s.length() - 1ull) * (s.length() - 2ull) / 2ull * 81ull;
    if (s.length() >= 2)
    {
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == '0')
            {
                continue;
            }
            else
            {
                ans += s[i] - '0';
                ans += (s.length() - (i + 1ull)) * 9ull;
                break;
            }
        }
    }
    return ans;
}

std::string s;
int k;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> s >> k;
    if (k == 1)
    {
        int x = s[0] - '0';
        std::cout << x + (s.length() - 1) * 9 << std::endl;
    }
    else if (k == 2)
    {

        std::cout << get2(s) << std::endl;
    }
    else
    {
        unsigned long long x = s[0] - '0';
        if (s.length() <= 2)
        {
            std::cout << 0 << std::endl;
            return 0;
        }
        unsigned long long ans = 0;
        ans += 1ull * (x - 1ull) * (s.length() - 1ull) * (s.length() - 2ull) / 2ull * 81ull;
        if (s.length() >= 4)
            ans += 1ull * (s.length() - 1ull) * (s.length() - 2ull) * (s.length() - 3ull) / 2ull * 243ull;
        ans += get2(s.substr(1, s.length() - 1));
        std::cout << ans << std::endl;
    }
    return 0;
}