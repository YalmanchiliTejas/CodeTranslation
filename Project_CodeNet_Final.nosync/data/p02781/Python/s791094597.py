n = input()
k = int(input())
l = len(n)
dp = [[[0,0] for j in range(5)] for i in range(l+1)]
dp[0][0][1] = 1
for i in range(l):
  for j in range(k+1):
    dp[i+1][j+1][0] += 9 * dp[i][j][0]
    dp[i+1][j  ][0] += dp[i][j][0]
    if n[i] == '0':
      dp[i+1][j  ][1] = dp[i][j][1]
    else:
      dp[i+1][j  ][0] += dp[i][j][1]
      dp[i+1][j+1][0] += (int(n[i]) - 1)*dp[i][j][1]
      dp[i+1][j+1][1] += dp[i][j][1]
print(dp[l][k][1] + dp[l][k][0] )
  