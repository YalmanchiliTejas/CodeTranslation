#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>
#include <list>
#include <queue>

#define LL long long
#define rep(i, n) for (LL i = 0; i < (LL)(n); i++)

using namespace std;

LL dan[50];

LL func(LL level, LL x)
{
    if (level == 0) {
        return 1;
    }

    if (x == 1) {
        return 0;
    } else if (x == dan[level - 1] + 2) {
        return func(level - 1, x - 1) + 1;
    } else if (x == dan[level]) {
        return func(level - 1, dan[level - 1]) * 2 + 1;
    } else if (x > dan[level - 1] + 1) {
        return func(level - 1, dan[level - 1]) +
            func(level - 1, x - (dan[level - 1] + 2)) + 1;
    } else { 
        return func(level - 1, x - 1);
    }
}

int main()
{
    LL n,x;
    cin >> n >> x;

    /* level0 は一段 */
    dan[0] = 1;
    for (int i = 1; i < n; i++) {
        /* 3はパティとバーガーが増えるの意味 */
        dan[i] = dan[i - 1] * 2 + 3;
    }

    cout << func(n, x) << endl;
}