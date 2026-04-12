# coding: utf-8
import sys
from functools import lru_cache

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
K = ir()

@lru_cache(None)
def solve(N, K):
    assert N >= 0
    if N < 10:
        if K == 0:
            return 1
        elif K == 1:
            return N
        else:
            return 0
    q, r = divmod(N, 10)
    ret = 0
    if K > 0:
        ret += solve(q, K-1) * r
        ret += solve(q-1, K-1) * (9-r)
    ret += solve(q, K)  # 一桁目が0
    return ret

answer = solve(N, K)
print(answer)
