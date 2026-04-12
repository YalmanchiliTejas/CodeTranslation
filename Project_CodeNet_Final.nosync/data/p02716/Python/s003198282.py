n = int(input())
l = list(map(int,input().split()))
dp = [[-float("INF")]*(3) for i in range(n+1)]
dp[0][0] = 0
dp[1][-1] = 0
dp[1][1] = l[0]
for i in range(1,n):  
    dp[i+1][-1] = max(dp[i][0],dp[i-1][-1]+l[i])
    dp[i+1][0] = max(dp[i][1],dp[i-1][0]+l[i])
    dp[i+1][1] = dp[i-1][1]+l[i]
    
print(max(dp[-1][0],dp[-1][-1]))

