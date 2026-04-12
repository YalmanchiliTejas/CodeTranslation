N = input()
K = int(input())

dp = [[[0] * 2 for j in range(K+1)] for i in range(len(N)+1)]

dp[0][0][0] = 1

for i in range(len(N)):
  n = int(N[i])
  for j in range(K+1):
    for ltn in range(2):
      for x in range(10 if ltn else n+1):
        if j + (x > 0) > K : continue
        dp[i+1][j + (x > 0)][ltn | (x < n)] += dp[i][j][ltn]

print(sum(dp[len(N)][K]))