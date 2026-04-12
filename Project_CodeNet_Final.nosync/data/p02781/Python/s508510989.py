from functools import lru_cache
import sys
sys.setrecursionlimit(1000000)

def g(m, k):
    if k == 0:
        return 1
    if k == 1:
        return m * 9
    if k == 2:
        return m * (m-1) // 2 * 81
    if k == 3:
        return m * (m-1) * (m-2) // 6 * 729

@lru_cache(maxsize=None)
def f(n, k):
    if n == 0 and k:
        return 0
    if k == 0:
        return 1
    S = str(n)
    t = int(S[0])
    m = len(S)
    return f(int("0" + S[1:]), k-1) + ((t-1) * g(m-1, k-1) if t else 0) + g(m-1, k)

N = int(input())
K = int(input())
print(f(N, K))