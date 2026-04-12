import sys
import math
import collections
import bisect
import itertools
import decimal

# import numpy as np

# sys.setrecursionlimit(10 ** 6)
INF = 10 ** 20
MOD = 10 ** 9 + 7
# MOD = 998244353

ni = lambda: int(sys.stdin.readline().rstrip())
ns = lambda: map(int, sys.stdin.readline().rstrip().split())
na = lambda: list(map(int, sys.stdin.readline().rstrip().split()))
na1 = lambda: list(map(lambda x: int(x) - 1, sys.stdin.readline().rstrip().split()))


# ===CODE===

def main():
    n = ni()
    a = na()

    cum = [0 for _ in range(n + 1)]
    for i, ai in enumerate(a):
        cum[i + 1] = cum[i] + ai
        # cum[i + 1] %= MOD

    ans = 0
    for i in range(n - 1):
        total = cum[-1] - cum[i + 1]
        total %= MOD
        ans += a[i] * total
        ans %= MOD

    print(ans)


if __name__ == '__main__':
    main()
