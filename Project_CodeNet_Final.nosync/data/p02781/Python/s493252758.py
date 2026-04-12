#E 復習復習
N = int(input())
K = int(input())
 
from functools import lru_cache
 
@lru_cache(None)
def f(n, K):
    if n <= 10:
        if K == 0:
            return 1
        if K == 1:
            return n
        return 0
    div_n = n//10
    mod_n = n%10
    ans = 0
#     if K >= 1:
    ans += f(div_n, K-1) * mod_n
    ans += f(div_n-1, K-1) * (9 - mod_n)
    ans += f(div_n, K)
    return ans
 
print(f(N, K))