import sys 
from functools import lru_cache
sys.setrecursionlimit(10**6)
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
MOD = 10**9+7
N = int(readline())
K = int(readline())
@lru_cache(None)
def f(N,K):
    if K == -1:
        return 0
    if N < 10:
        if K == 0:
            return 1
        elif K == 1:
            return N
        else:
            return 0
    ans = 0
    q, mod = divmod(N, 10)
    ans += f(q,K) + mod * f(q,K-1) + (9-mod) * f(q-1,K-1) 
    return ans
print(f(N,K))