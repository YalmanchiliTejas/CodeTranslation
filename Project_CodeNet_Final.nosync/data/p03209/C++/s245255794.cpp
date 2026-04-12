#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_N = 50;

long long thickness[MAX_N + 1];

void thickness_init()
{
    thickness[0] = 1;
    for (int i = 1; i < MAX_N + 1; i++) {
        thickness[i] = thickness[i-1] * 2 + 3;
    }
}

long long rec(int level, long long x) {
    if (x == 0) return 0;
    if (level == 0 && x == 1) return 1;

    long long ret = 0;

    if (1 <= x && x <= thickness[level-1]+1)
    {
        ret = rec(level-1, x-1);
    }
    else if (thickness[level-1]+1 < x && x < thickness[level]) {
        ret = rec(level-1, thickness[level-1]) + 1 + rec(level-1, x - 2 - thickness[level-1]);
    }
    else if (x == thickness[level])
    {
        ret = 2 * rec(level-1, thickness[level-1]) + 1;
    }
    return ret;
}

int main()
{
    thickness_init();
    long long n, x;
    std::cin >> n >> x;
    std::cout << rec(n, x) << std::endl;
    return 0;
}