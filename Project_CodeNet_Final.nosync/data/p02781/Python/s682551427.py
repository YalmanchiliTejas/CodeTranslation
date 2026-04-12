from functools import lru_cache
from sys import setrecursionlimit
setrecursionlimit(10000)
N = input()
K = int(input())

@lru_cache()
def f(n, k):
    if k == 0:
        return 1
    if len(n) == 1:
        if k == 1:
            return int(n)
        else:
            return 0
    m = int(n[-1])
    return f(n[:-1], k) + f(n[:-1], k - 1) * m + f(str(int(n[:-1]) - 1), k - 1) * (9 - m)

print(f(N, K))