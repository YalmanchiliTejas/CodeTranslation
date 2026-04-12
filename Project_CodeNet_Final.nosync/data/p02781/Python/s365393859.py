from collections import defaultdict
from functools import lru_cache

N = input().strip()
K = int(input().strip())
lenN = len(N)

#memo = defaultdict(lambda :defaultdict(lambda :defaultdict(int)))
@lru_cache(maxsize=None)
def f(keta, flag, k):
    if keta == lenN-1:
        if k == K:
            return 1
        else:
            return 0
    #if keta in memo and flag in memo[keta] and k in memo[keta][flag]:
    #    return memo[keta][flag][k]
    nketa = keta + 1
    maxi = int(N[nketa]) if flag else 9
    res = 0
    for i in range(maxi+1):
        nflag = flag and (int(N[nketa]) == i)
        nk = k if i == 0 else k + 1
        if nk > K:
            continue
        res += f(nketa, nflag, nk)
    #memo[keta][flag][k] = res
    return res

print(f(-1, True, 0))
