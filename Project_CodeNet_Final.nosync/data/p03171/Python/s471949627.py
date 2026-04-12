n = int(input())
a = list(map(int, input().split()))

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(n):
    dp[i][i]=0

for l in range(1,n+1):
    for i in range(n+1):
        j=i+l
        if j>n:
            continue

        if (n-l)%2==0: # sente

            dp[i][j]= max(a[j-1]+dp[i][j-1],a[i]+dp[i+1][j])

        else: # gote
            dp[i][j]= min(-a[j-1]+dp[i][j-1],-a[i]+dp[i+1][j])

print(dp[0][n])