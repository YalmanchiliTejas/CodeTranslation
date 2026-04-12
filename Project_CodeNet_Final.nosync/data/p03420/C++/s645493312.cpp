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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
using lint = long long;

lint cand_num(lint n, lint b, lint k)
{
    if (k == 0)
        return n;
    if (b <= k)
        return 0;
    lint out = 0;
    lint onecycle = b - k;

    out += (n / b) * onecycle;
    out += std::max(0ll, n % b - (k - 1));

    return out;
}

int main()
{
    lint n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);

    lint ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        ans += cand_num(n, i, k);
    }

    printf("%lld", ans);
    return 0;
}
