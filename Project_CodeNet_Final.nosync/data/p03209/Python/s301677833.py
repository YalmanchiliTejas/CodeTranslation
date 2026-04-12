N,X=map(int,input().split())

from functools import lru_cache
import sys

sys.setrecursionlimit(10*20)

@lru_cache(maxsize=None)
def count(N):
    if N == 0:
        return 1
    else:
        return 3 + 2 * count(N-1)
    
@lru_cache(maxsize=None)
def calc(N,X):
    if N == 0:
        return 1
    center = count(N-1) + 1
    if X == 0 :
        return 0
    elif X < center:
        return calc(N-1,X-1)
    elif X == center:
        return calc(N-1,center-2) + 1
    elif X > center:
        return calc(N-1,X-center-1) + calc(N,center)
print(calc(N,X-1))