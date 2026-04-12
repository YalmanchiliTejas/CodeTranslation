from functools import lru_cache

N=int(input())
K =int(input()) 

@lru_cache(None)
def dp(N, K):
  if N < 10:
    if K == 0:
      return 1
    if K == 1:
      return N
    return 0
  q, r = divmod(N, 10)
  ret = 0
  if K >= 1: # 下一桁が0でないときはKを1消化
    ret += dp(q, K-1) * r # 下一桁がr以下の時
    ret += dp(q-1, K-1) * (9-r) # 下一桁がrより上の時はq-1であれば成立
  ret += dp(q, K) # 下一桁が0のとき
  return ret

print(dp(N, K))