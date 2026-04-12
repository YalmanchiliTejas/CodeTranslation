from sys import stdin
from functools import lru_cache

@lru_cache(None)
def solver(N, K):
    if N < 10:
        if K == 0:
            return 1
        if K == 1:
            return N
        return 0
    m, r = divmod(N,10)
    ans = 0
    if K >= 1:
        ans += solver(m, K-1) * r
        ans += solver(m-1, K-1) * (9-r)
    ans += solver(m, K)
    return ans


n = int(input())
k = int(input())
print(solver(n,k))
