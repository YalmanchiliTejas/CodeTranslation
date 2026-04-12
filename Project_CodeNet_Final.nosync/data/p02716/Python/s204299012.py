import sys
sys.setrecursionlimit(10**7)

from functools import lru_cache

@lru_cache(None)
def dfs(p, remain):

    n = len(arr)

    if remain == 0 or p >= n:
        return 0

    if remain == 1:
        return max(arr[p:])
        
    len_remain = n - (p + 1)

    t = -float('inf')
    if (remain - 1) * 2 + 1 <= len_remain:
        t = dfs(p + 1, remain)

    t2 = arr[p] + dfs(p + 2, remain - 1)

    return max(t, t2)

    


n = int(input())

arr = list(map(int, input().split()))

ans = dfs(0, n // 2)

print (ans)

