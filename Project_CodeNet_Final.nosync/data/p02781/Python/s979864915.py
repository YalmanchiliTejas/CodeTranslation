#これはmaspyさんの提出コードの写経です
from sys import setrecursionlimit
setrecursionlimit(10**6) 

from sys import stdin
from functools import lru_cache
n = int(stdin.readline().rstrip())
k = int(stdin.readline().rstrip())
#n以下の数字で0でないものがちょうどk個
@lru_cache(maxsize=None)
def kosuu(n,k):
    #残り10以下の場合
    if n < 10:
        if k == 0:
            return 1
        if k == 1:
            return n
        return 0
    q = n//10#商
    r = n%10#余り
    ret = 0
    if k >= 1:
        # 1の位が nonzero
        ret += kosuu(q, k-1) * r
        ret += kosuu(q-1, k-1) * (9-r)
    ret += kosuu(q,k)
    return ret
print(kosuu(n,k))