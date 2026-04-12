def main():
    n = int(input())
    a = list(map(int, input().split()))
    if n % 2 == 0:
        dp = [[[-10**18]*2, [-10**18]*2] for _ in [0]*(n+1)]
        dp[0][0][0] = 0
        for i in range(n):
            # 使う場合
            dp[i+1][1][0] = max(dp[i+1][1][0], dp[i][0][0]+a[i])
            dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][0][1]+a[i])
            # 使わない場合
            dp[i+1][0][1] = max(dp[i+1][0][1], dp[i][0][0])
            # 更新
            dp[i+1][0][0] = max(dp[i+1][0][0], dp[i][1][0])
            dp[i+1][0][1] = max(dp[i+1][0][1], dp[i][1][1])
        print(max(dp[n][1][1], dp[n][0][0]))
        return
    dp = [[[-10**18]*3, [-10**18]*3] for _ in [0]*(n+1)]
    dp[0][0][0] = 0
    for i in range(n):
        # 使う場合
        dp[i+1][1][0] = max(dp[i+1][1][0], dp[i][0][0]+a[i])
        dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][0][1]+a[i])
        dp[i+1][1][2] = max(dp[i+1][1][2], dp[i][0][2]+a[i])
        # 使わない場合
        dp[i+1][0][1] = max(dp[i+1][0][1], dp[i][0][0])
        dp[i+1][0][2] = max(dp[i+1][0][2], dp[i][0][1])
        # 更新
        dp[i+1][0][0] = max(dp[i+1][0][0], dp[i][1][0])
        dp[i+1][0][1] = max(dp[i+1][0][1], dp[i][1][1])
        dp[i+1][0][2] = max(dp[i+1][0][2], dp[i][1][2])
    print(max(dp[n][1][2], dp[n][0][1]))


main()
