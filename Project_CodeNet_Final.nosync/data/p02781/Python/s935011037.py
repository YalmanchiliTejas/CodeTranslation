N = input()
L = len(N)
K = int(input())

dp = [ [ [0]*2 for _ in range(4) ] for _ in range(L+1) ]
dp[0][0][0] = 1
for i in range(L):
  for j in range(K+1):
    for k in range(2):
      nd = int(N[i])
      for d in range(10):
        ni = i+1
        nj = j
        nk = k
        if d != 0: nj += 1
        if nj > K: continue
        if k==0:
          if d > nd: continue
          if d < nd: nk = 1

        dp[ni][nj][nk] += dp[i][j][k]

print(dp[L][K][0] + dp[L][K][1])