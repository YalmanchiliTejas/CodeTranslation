N = int(input())
K = int(input())
from functools import lru_cache

@lru_cache(maxsize=100000000000)
def dp(n, k): #0以上n以下の数で０でない数字がちょうどk個あるもの。
  if k == 0:
    return 1
  elif n == 0:
    return 0
  else:
    n = int(n)
    s = str(n)
    digit = len(s)
    m, fdigit = divmod(n,10)
    if m >= 1:
        return int(dp(m, k-1) * fdigit + dp(m-1, k-1)* (9-fdigit) + dp(m, k))
    elif k == 1:
        return n
    elif k == 2 or k == 3:
        return 0
    else:
        return 1
if K == 0:
    answer = dp(N, K)-1
else:
    answer = dp(N, K)
print(int(answer))