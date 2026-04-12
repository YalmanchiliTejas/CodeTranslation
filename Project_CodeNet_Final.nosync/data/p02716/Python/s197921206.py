n = int(input())
a = list(map(int, input().split()))
inf = 10**18
if n%2 == 0:
    dp = [[-inf]*2 for _ in range(n+2)]
    dp[-2][0] = 0
    for i in range(n):
        for j in range(2):
            for k in range(2):
                if j-k>=0:
                    dp[i][j] = max(dp[i][j], dp[i-k-2][j-k]+a[i])
    print(max(max(dp[n-1]), max(dp[n-2][:1])))
else:
    dp = [[-inf]*3 for _ in range(n+2)]
    dp[-2][0] = 0
    for i in range(n):
        for j in range(3):
            for k in range(3):
                if j-k>=0:
                    dp[i][j] = max(dp[i][j], dp[i-k-2][j-k]+a[i])
    print(max(max(dp[n-1][1:]), max(dp[n-2][:2]), max(dp[n-3][:1])))


