n = input()
n_l = len(n)
k = int(input())

# dp[i][j][s] = 左からi番目の桁までで0でない数がj個である数の個数の総和（sは未満フラグ）
dp = [[[0]*2 for j in range(100+2)] for i in range(n_l+1)]
dp[0][0][0] = 1

for i in range(1,n_l+1) :
  m = int(n[i-1])
  for s in range(2) :
    for j in range(100+1) :
      if s == 0 :
        for num in range(m+1) :
          if num == m :
            if num == 0 :
              dp[i][j][0] += dp[i-1][j][0]
            else :
              dp[i][j+1][0] += dp[i-1][j][0]
          else :
            if num == 0 :
              dp[i][j][1] += dp[i-1][j][0]
            else :
              dp[i][j+1][1] += dp[i-1][j][0]
      else :
        for num in range(10) :
          if num == 0 :
            dp[i][j][1] += dp[i-1][j][1]
          else :
            dp[i][j+1][1] += dp[i-1][j][1]
            
print(dp[n_l][k][0]+dp[n_l][k][1])