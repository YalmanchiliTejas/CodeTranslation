N = int(input())
a = list(map(int, input().split()))
dp = [[0]*N for _ in range(N)]

for l in range(N):
    for i in range(N):
        j = i+l
        
        if j>=N:
            continue
        
        if (N-l-1)%2==0:
            if i==j:
                dp[i][j] = a[i]
            else:
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j])
        else:
            if i==j:
                dp[i][j] = -a[i]
            else:
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j])
    
print(dp[0][N-1])