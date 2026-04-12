n = input()
k = int(input())
l = len(n)
dp = [[[0] * (k+1) for _ in range(2)] for _ in range(l+1)]
dp[0][0][0] = 1

for i in range(1, l+1):
    m = int(n[i-1])
    for j in range(k+1):
        
        dp[i][1][j] += dp[i-1][1][j]*1  # 0
        if j - 1 >= 0:
            dp[i][1][j] += dp[i-1][1][j-1]*9  # 1〜9
            
        if m == 0:
            pass
        elif m >= 1:
            dp[i][1][j] += dp[i-1][0][j]
            if j - 1>= 0:
                dp[i][1][j] += dp[i-1][0][j-1]*(m-1)
        
        if m == 0:
            dp[i][0][j] += dp[i-1][0][j]
        else:
            if j - 1>= 0:
                dp[i][0][j] += dp[i-1][0][j-1]
        
print(dp[-1][0][k] + dp[-1][1][k])