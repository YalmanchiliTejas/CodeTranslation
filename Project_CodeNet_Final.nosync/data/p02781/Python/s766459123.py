from functools import lru_cache
import sys
sys.setrecursionlimit(10**7)
n = int(input())
k = int(input())


@lru_cache(maxsize=None)
def f(n, k):
    if k == 0:
        return 1
    if len(str(n)) == 1:
        if k >= 2:
            return 0
        if k == 1:
            return n

    r = n % 10
    m = (n - r) // 10
    return r * f(m, k-1) + (9 - r) * f(m-1, k-1) + f(m, k)


print(f(n, k))
