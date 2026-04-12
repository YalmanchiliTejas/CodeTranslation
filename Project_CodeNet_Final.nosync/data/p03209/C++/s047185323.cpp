#include <iostream>

using namespace std;

u_int64_t height[51];
u_int64_t pates[51];

u_int64_t solve(int level, u_int64_t x)
{
    u_int64_t result = 0;

    if (x == 0)
    {
        return 0;
    }
    if (level == 0)
    {
        return 1;
    }

    if (x <= 1)
    {
        return result;
    }
    x -= 1;

    if (x <= height[level - 1])
    {
        return solve(level - 1, x);
    }
    result += pates[level - 1];
    x -= height[level - 1];

    result += 1;
    if (x <= 1)
    {
        return result;
    }
    x -= 1;

    if (x <= height[level - 1])
    {
        return result + solve(level - 1, x);
    }
    result += pates[level - 1];
    x -= height[level - 1];

    return result;
}

int main()
{
    int N;
    u_int64_t X;
    cin >> N >> X;

    pates[0] = 1;
    height[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        pates[i] = 2 * pates[i - 1] + 1;
        height[i] = 2 * height[i - 1] + 3;
    }

    u_int64_t result = solve(N, X);
    cout << result << endl;
}