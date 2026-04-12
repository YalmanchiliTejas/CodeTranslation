n = input()
k = int(input())

kt = len(n)
dp = [[[0] * 4 for _ in range(2)] for _ in range(kt+1)]
dp[0][1][0] = 1

for i in range(kt):
    x = int(n[i])
    dp[i+1][0][0] = 1
    
    for j in range(3):
        if x == 0:
            dp[i+1][1][j+1] = dp[i][1][j+1]
            dp[i+1][0][j+1] = dp[i][0][j] * 9 + dp[i][0][j+1]
        else:
            dp[i+1][1][j+1] = dp[i][1][j]  
            dp[i+1][0][j+1] = dp[i][0][j] * 9 + dp[i][0][j+1] + dp[i][1][j] * (x-1) +  dp[i][1][j+1]
            
print(dp[kt][0][k] + dp[kt][1][k])