#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
long long calc(long long n, long long k)
{
    switch (k)
    {
    case 1:
        return n;
    case 2:
        return n * (n - 1) / 2;
    case 3:
        return n * (n - 1) * (n - 2) / 6;
    }
    return 1;
}

long long calc2(long k)
{
    switch (k)
    {
    case 1:
        return 9;
    case 2:
        return 81;
    case 3:
        return 729;
    }
    return 1;
}

long long count(std::string s, long i, long n, long k)
{
    if (n < k)
    {
        return 0;
    }
    if (k == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return s[i] - '0';
    }
    return ((s[i] - '1') <= 0 ? 0 : (s[i] - '1')) * calc(n - 1, k - 1) * calc2(k - 1) + (s[i] == '0' ? count(s, i + 1, n - 1, k) : calc(n - 1, k) * calc2(k)) + (s[i] == '0' ? 0 : count(s, i + 1, n - 1, k - 1));
}

int main()
{
    long long n, ans, k;
    std::string s;
    std::cin >> s;
    std::cin >> k;
    n = s.length();
    ans = count(s, 0, n, k);

    std::cout << ans << std::endl;
}