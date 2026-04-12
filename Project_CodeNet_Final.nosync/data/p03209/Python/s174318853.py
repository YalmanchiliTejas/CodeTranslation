import sys
import math
import fractions
from collections import deque
from collections import defaultdict
sys.setrecursionlimit(10**7)

N, X = map(int, input().split())

g = [1] * 51
p = [1] * 51

for i in range(1, 51):
    g[i] = 2 * g[i - 1] + 3
    p[i] = 2 * p[i - 1] + 1


def rec(n, x):
    if n == 0:
        if x == 0:
            return 0
        elif x == 1:
            return 1
    if x == 1:
        return 0

    if x <= g[n - 1] + 1:
        return rec(n - 1, x - 1)
    elif x == g[n - 1] + 2:
        return p[n - 1] + 1
    elif x <= 2 * g[n - 1] + 2:
        return rec(n - 1, x - g[n - 1] - 2) + p[n - 1] + 1
    else:
        return p[n]


ans = rec(N, X)
print(ans)
