import os
import sys
from functools import lru_cache

from scipy.misc import comb

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7
# MOD = 998244353

N, K = [int(sys.stdin.buffer.readline()) for _ in range(2)]
N = str(N)


@lru_cache(maxsize=None)
def solve(d, k):
    # 下d桁でk個選ぶ
    if d <= 0:
        return 0
    if k == 0:
        return 1
    n = int(N[-d])
    if d == 1:
        if k == 0:
            return 1
        elif k == 1:
            return n
        else:
            return 0
    if n == 0:
        return solve(d - 1, k)
    ret = 0
    # n を選ぶ
    ret += solve(d - 1, k - 1)
    # n より小さい数を選ぶ
    ret += comb(d - 1, k - 1, exact=True) * (n - 1) * 9 ** (k - 1)
    # 0 を選ぶ
    ret += comb(d - 1, k, exact=True) * 9 ** k
    return ret


ans = solve(len(N), K)
print(ans)
