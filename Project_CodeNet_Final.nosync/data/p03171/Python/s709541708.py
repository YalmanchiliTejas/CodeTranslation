N = int(input())
A = list(map(int, input().split()))
#import random
#N = 3000
#A = [random.randint(1, 10**9) for _ in range(N)]


dp = [[0] * (N+1) for _ in range(N+1)]
for g in range(N):
  for l in range(N-g):
    r = l + g
    n = r - l
    s = -1 if (N-n) % 2 == 0 else 1
    lv = dp[l+1][r] + s*A[l]
    rv = dp[l][r-1] + s*A[r]
    if s*lv > s*rv:
      dp[l][r] = lv
    else:
      dp[l][r] = rv

print(dp[0][N-1])

