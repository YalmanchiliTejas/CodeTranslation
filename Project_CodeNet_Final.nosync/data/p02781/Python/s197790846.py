from operator import mul
from functools import reduce
from functools import lru_cache


def cmb(n, r):
    # combination
    if n < 1 or r < 0:
        return 0
    if n < r:
        return 0
    r = min(n - r, r)
    if r == 0:
        return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1, r + 1))
    return over // under


@lru_cache(maxsize=None)
def solve(N, k):
    if len(N) > 1 and N[0] == "0":
        return solve(N[1:], k)
    n = int(N)
    if k < 0:
        return 0
    elif len(N) < k:
        return 0
    elif n == 0:
        if k == 0:
            return 1
        elif k > 0:
            return 0
    elif n < 10:
        if k == 1:
            return n
        elif k == 0:
            return 1

    a = solve(N[1:], k - 1)
    b = (int(N[0]) - 1) * cmb(len(N) - 1, k - 1) * int(9**(k - 1))
    c = cmb(len(N) - 1, k) * int(9**k)
    # print(N, k, a, b, c)
    return a + b + c


N = int(input())
K = int(input())

L = len(str(N))

# print(ans)
print(solve(str(N), K))
