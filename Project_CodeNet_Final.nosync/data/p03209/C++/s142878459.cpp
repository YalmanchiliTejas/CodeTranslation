#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>
using lint = long long;

std::vector<lint> level_n, p_n;

lint eat_p(lint x, lint n)
{
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (x == 1)
    {
        return 0;
    }
    if (x <= level_n[n - 1] + 1)
    {
        return eat_p(x - 1, n - 1);
    }
    else if (x == level_n[n - 1] + 2)
    {
        return p_n[n - 1] + 1;
    }
    else if (x == level_n[n])
    {
        return p_n[n];
    }
    else
    {
        return p_n[n - 1] + 1 + eat_p(x - level_n[n - 1] - 2, n - 1);
    }
}

int main()
{
    lint n, x;

    for (int i = 0; i < 51; ++i)
    {
        level_n.push_back(pow(2, i + 2) - 3);
        p_n.push_back(pow(2, i + 1) - 1);
    }

    scanf("%lld", &n);
    scanf("%lld", &x);

    printf("%lld", eat_p(x, n));

    return 0;
}
