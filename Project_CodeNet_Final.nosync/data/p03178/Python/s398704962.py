def solve():
  K = list(map(int,list(input())))
  digit = len(K)
  D = int(input())
  dp = [[[0]*D for _ in range(2)] for _ in range(digit+1)]
  dp[0][1][0] = 1
  mod = 10**9+7
  for k in range(1,digit+1):
    for d in range(D):
      dp[k][1][d] = dp[k-1][1][(d-K[k-1])%D]
      for p in range(10):
        dp[k][0][d] += dp[k-1][0][(d-p)%D] 
      for p in range(K[k-1]):
        dp[k][0][d] += dp[k-1][1][(d-p)%D]
      dp[k][0][d] %= mod
  ans = (dp[-1][0][0]+dp[-1][1][0]-1)%mod
  return ans
print(solve())