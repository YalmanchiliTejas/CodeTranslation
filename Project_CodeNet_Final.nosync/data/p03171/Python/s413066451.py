n = int(input())
a = list(map(int, input().split()))

dp = [[0]*(n+1) for i in range(n+1) ]
for cnt in range(1, n+1):
    i = 0
    while True:
        j = i + cnt
        if j-1 >= n:
            break
        dp[i][j] = max(a[i] - dp[i+1][j], a[j-1] - dp[i][j-1])
        i += 1
print(dp[0][n])