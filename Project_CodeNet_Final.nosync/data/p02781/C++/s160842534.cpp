#include <iostream>
#include <cstring>

std::string N;
int K;
int dp[101][4][2];

int rec(int n, int k, bool f)
{
    int &res = dp[n][k][f];
    if (res != -1)
        return res;

    if (n == (int)N.size())
        return k == K;

    res = 0;
    int x = N[n] - '0';
    if (k < K) {
        if (!f) {
            for (int i = 1; i <= x; i++)
                if (i == x)
                    res += rec(n + 1, k + 1, f);
                else
                    res += rec(n + 1, k + 1, 1);
        }
        else
            for (int i = 1; i <= 9; i++)
                res += rec(n + 1, k + 1, 1);
    }

    if (x == 0)
        res += rec(n + 1, k, f);
    else
        res += rec(n + 1, k, 1);

    return res;
}

int main()
{
    std::cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    std::cout << rec(0, 0, 0) << std::endl;
    return 0;
}