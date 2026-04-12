N = int(input())
K = int(input())

N_ = str(N)
n = len(N_)

dp = [[[0]*2 for i in range(5)] for j in range(110)]

dp[0][0][0] = 1
dp[0][0][1] = 0

for i in range(n):
  for j in range(4):
    for k in range(2):
      nd = int(N_[i])
      for d in range(10):
        ni = i+1
        nj = j
        nk = k
        if d != 0:
          nj += 1
        if nj >3:
          continue
        if k == 0:
          if d > nd:
            continue
          elif d < nd:
            nk = 1
          else:
            pass
        dp[ni][nj][nk] += dp[i][j][k]
        
print(sum(dp[n][K]))