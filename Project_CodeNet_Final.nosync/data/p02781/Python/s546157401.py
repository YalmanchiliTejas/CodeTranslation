s = input()
K = int(input())
n = len(s)

dp = [[[0]*5 for _ in range(2)] for _ in range(10001)]
dp[0][0][0] = 1

for i in range(n):
  for k in range(K+1):
    x = int(s[i])
    
    dp[i+1][1][k+1] += dp[i][1][k] * 9
    dp[i+1][1][k]   += dp[i][1][k]        
    
    if x > 0:
      dp[i+1][1][k+1] += dp[i][0][k] * (x-1)
      dp[i+1][1][k]   += dp[i][0][k]
      dp[i+1][0][k+1] = dp[i][0][k]
    else:
      dp[i+1][0][k] = dp[i][0][k]
      
print( dp[n][0][k]+ dp[n][1][k])      
