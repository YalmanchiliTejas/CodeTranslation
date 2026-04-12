N = input()
K = int(input())

l = len(N)

dp = [[[0]*(K+1) for _ in range(2)] for _ in range(l)]
dp[0][0][1] = 1
dp[0][1][1] = int(N[0]) - 1
dp[0][1][0] = 1
#print(dp[0])

for i in range(1,l):
  for j in range(K+1):
    if int(N[i]) == 0:
      if j > 0:
        dp[i][0][j] = dp[i-1][0][j]
        dp[i][1][j] += 9*dp[i-1][1][j-1]
    else:
      if j > 0:
        dp[i][0][j] = dp[i-1][0][j-1]
        dp[i][1][j] += dp[i-1][0][j-1]*(int(N[i])-1) + 9*dp[i-1][1][j-1]
      dp[i][1][j] += dp[i-1][0][j]
    dp[i][1][j] += dp[i-1][1][j]

  #print(dp[i])
print(dp[l-1][0][K]+dp[l-1][1][K])