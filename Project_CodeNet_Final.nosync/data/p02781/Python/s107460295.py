n = input()
k = int(input())
dp = [[[0 for i in range(k+1)] for i in range(2)] for i in range(len(n)+1)]
dp[0][0][0] = 1
for a in range(len(n)):
  for b in range(2):
    for c in range(k+1):
      for i in range(10):
        if b ==1:
          if c ==k:  
            if i == 0:
              dp[a+1][1][c] += dp[a][1][c]
          else:
            if i == 0:
              dp[a+1][1][c] += dp[a][1][c]
            else:
              dp[a+1][1][c+1] += dp[a][1][c]
        else:
          if int(n[a]) > i:
            if c == k:
              if i == 0:
                dp[a+1][1][c] += dp[a][0][c]
            else:
              if i == 0:
                dp[a+1][1][c] += dp[a][0][c]
              else:
                dp[a+1][1][c+1] += dp[a][0][c]
          if int(n[a]) == i:
            if c == k:
              if i == 0:
                dp[a+1][0][c] += dp[a][0][c]
            else:
              if i == 0:
                dp[a+1][0][c] += dp[a][0][c]
              else:
                dp[a+1][0][c+1] += dp[a][0][c]
            
            
print(dp[-1][0][-1] + dp[-1][1][-1])
        