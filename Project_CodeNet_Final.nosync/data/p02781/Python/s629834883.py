n = input()
k = int(input())
nl = len(n)

dp = [[[0]*(k+1) for _ in range(2)]for _ in range(nl+1)]
#dp[i][j][k] i:上からの桁数、j:smaller flag、k:0以外の数字の個数
dp[0][0][0] = 1

for i in range(nl):
  for j in range(2):
    for l in range(k+1):
      c = int(n[i])
      if j == 1:
        dp[i+1][j][l] += dp[i][j][l]
        if l < k:
          dp[i+1][j][l+1] += dp[i][j][l]*9
      else:
        if c == 0:#0しか選べない上にsmallを確定できない
          dp[i+1][0][l] += dp[i][j][l]
        else:
          dp[i+1][1][l] += dp[i][j][l]#cより確実に小さい0を使う。small確定
          if l < k:
            dp[i+1][1][l+1] += dp[i][j][l]*(c-1) #c以下の数字を使えばsmall確定
            dp[i+1][0][l+1] += dp[i][j][l] #cを使ったらsmall確定できない
            
print(dp[nl][0][k]+dp[nl][1][k])