#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// c が得する場合、c を優先的に買う形に最適化
int solve2(int a, int b, int c, int x, int y)
{
    // c が得でない場合は、a, b をそのまま買っておしまい
    if(a + b <= c * 2)
    {
        return a * x + b * y;
    }

    auto cCount = min(x, y) * 2;

    if(x == y)
    {
        return cCount * c;
    }
    else if(x > y)
    {
        auto shortageA = x - y;
        auto perCost = min(c * 2, a);
        return perCost * shortageA + cCount * c;
    }
    else
    {
        auto shortageB = y - x;
        auto perCost = min(c * 2, b);
        return perCost * shortageB + cCount * c;
    }
}

// 単純な全探索
int solve(int a, int b, int c, int x, int y)
{
    int minCost = numeric_limits<int>::max();
    for(int i = 0; i <= x; ++i)
    {
        for(int j = 0; j <= y; ++j)
        {
            int shortageA = x - i;
            int shortageB = y - j;
            int abCount = max(shortageA, shortageB) * 2;

            int cost = a * i + b * j + c * abCount;
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int main(int argc, const char* argv[])
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    cout << solve2(a, b, c, x, y) << endl;

    return 0;
}