n = int(input())
a = [0]+list(map(int,input().split()))
dp = [[0]*2 for _ in range(n+1)]
dp[1][1] = a[1]
dp[2][1] = max(a[1],a[2])

for i in range(3,n+1):
    if i % 2 == 1:
        dp[i][0] = max(dp[i-1][1],dp[i-2][0]+a[i])
        dp[i][1] = dp[i-2][1]+a[i]
    else:
        dp[i][0] = max(dp[i-1][0],dp[i-2][0]+a[i])
        dp[i][1] = max(dp[i-1][1],dp[i-2][1]+a[i])
if n % 2 == 1:
    print(dp[-1][0])
else:
    print(dp[-1][1])
#print(dp)