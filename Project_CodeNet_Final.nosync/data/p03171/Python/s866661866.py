from sys import stdin
n = int(stdin.readline())
arr = list(map(int,stdin.readline().split()))
dp = [[0]*(n+1) for _ in range(n+1)]
i=j=n-1
for i in range(n-1,-1,-1):
    for j in range(1,n+1):
        if i>j-1:
            continue
        if ((j-i)%2)^(n%2):
            dp[i][j] = min(-arr[i]+dp[i+1][j],-arr[j-1]+dp[i][j-1])
        else:
            dp[i][j] = max(arr[i]+dp[i+1][j],arr[j-1]+dp[i][j-1])
print(dp[0][n])