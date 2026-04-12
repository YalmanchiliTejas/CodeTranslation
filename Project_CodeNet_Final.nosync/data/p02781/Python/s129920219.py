n = input()
k = int(input())
dp = [[0] * (3 + 1) for i in range(len(n))]
dp[0][1] = int(n[0])
cnt = 1
for i in range(1, len(n)):
  m = int(n[i])
  if cnt == 1:
    dp[i][1] = 9 + dp[i - 1][1]
    dp[i][2] = (dp[i - 1][1] - 1) * 9 + dp[i - 1][2] + m
    dp[i][3] = dp[i - 1][2] * 9 + dp[i - 1][3]
  elif cnt == 2:
    dp[i][1] = 9 + dp[i - 1][1]
    dp[i][2] = dp[i - 1][1] * 9 + dp[i - 1][2]
    dp[i][3] = (dp[i - 1][2] - 1) * 9 + dp[i - 1][3] + m
  else:
    dp[i][1] = 9 + dp[i - 1][1]
    dp[i][2] = dp[i - 1][1] * 9 + dp[i - 1][2]
    dp[i][3] = dp[i - 1][2] * 9 + dp[i - 1][3]
  if m != 0:
    cnt += 1
print(dp[len(n) - 1][k])