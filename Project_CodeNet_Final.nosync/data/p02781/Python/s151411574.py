from functools import lru_cache
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N, K = map(int,read().split())

@lru_cache(None)
def F(N, K):
    if N < 10:
        if K == 0:
            return 1
        if K == 1:
            return N
        return 0
    q, r = divmod(N, 10)
    ret = 0
    if K >= 1:
        ret += F(q, K-1) * r
        ret += F(q-1, K-1) * (9-r)
    ret += F(q, K)
    return ret

print(F(N, K))