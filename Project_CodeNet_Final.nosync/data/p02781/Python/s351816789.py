n = input()
k = int(input())
l = len(n)
dp = [[[0 for i in range(2)] for t in range(3+1)] for j in range(l+1)]
dp[0][0][0] = 1
for i in range(1,l+1):
  for j in range(k+1):
    x = int(n[i-1])
    if x != 0:
      for m in range(1,3+1):
        dp[i][m][0] = dp[i-1][m-1][0]
    else:
      for m in range(3+1):
        dp[i][m][0] = dp[i-1][m][0]
    dp[i][0][1] = dp[i-1][0][0]+dp[i-1][0][1]
    dp[i][1][1] = dp[i-1][0][1]*9+dp[i-1][1][1]+dp[i-1][0][0]*(max(0,x-1))+dp[i-1][1][0]*(x>0)
    dp[i][2][1] = dp[i-1][1][1]*9+dp[i-1][2][1]+dp[i-1][1][0]*(max(0,x-1))+dp[i-1][2][0]*(x>0)
    dp[i][3][1] = dp[i-1][2][1]*9+dp[i-1][3][1]+dp[i-1][2][0]*(max(0,x-1))+dp[i-1][3][0]*(x>0)
print(dp[l][k][0]+dp[l][k][1])