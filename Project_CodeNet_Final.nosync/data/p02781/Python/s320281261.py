from functools import lru_cache
from operator import mul
from functools import reduce


def cmb(n, r):
    r = min(n - r, r)
    if r == 0:
        return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1, r + 1))
    return over // under


N = list(input())
N = list(map(int, N))
K = int(input())
n = len(N)


@lru_cache(None)
def rec(i, k, yn):
    if k == 0:
        return 1
    elif i == n:
        return 0
    if n - i < k:
        return 0

    if yn:
        # i桁目がNより小さいとき
        return cmb(n - i, k) * pow(9, k)
    else:
        if N[i] == 0:
            return rec(i + 1, k, False)
        else:
            a = rec(i + 1, k, True)
            b = rec(i + 1, k - 1, True) * (N[i] - 1)
            c = rec(i + 1, k - 1, False)
            return a + b + c


answer = rec(0, K, False)
print(answer)
