import sys
import math
sys.setrecursionlimit(1000000)


N = int(input())
K = int(input())

from functools import lru_cache

@lru_cache(maxsize=10000)
def f(n,k):
    # print('n:{},k:{}'.format(n,k))
    if k == 0:
        return 1
    if k== 1 and n < 10:
        return n

    keta = len(str(n))
    if keta < k:
        return 0

    h = n // (10 ** (keta-1))
    b = n % (10 ** (keta-1))

    ret = 0
    for i in range(h+1):
        if i==0:
            ret += f(10 ** (keta-1) - 1, k)
        elif 1 <= i < h:
            ret += f(10 ** (keta-1) - 1, k-1)
        else:
            ret += f(b,k-1)
        
    return ret

print(f(N,K))