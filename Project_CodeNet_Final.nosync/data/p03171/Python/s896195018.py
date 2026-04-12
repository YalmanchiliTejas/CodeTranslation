n = int(input())
a = list(map(int,input().split()))

dp = [[0]*n for _ in range(n)]
# dp[i][j] : 残っている石がi からj の時の手番から見た終了得点の最大値

for i in range(n):
    dp[i][i] = a[i]
for j in range(1,n):
    for i in range(n-j):
        dp[i][i+j] = max(a[i]-dp[i+1][i+j], a[i+j]-dp[i][i+j-1])
print(dp[0][n-1])
