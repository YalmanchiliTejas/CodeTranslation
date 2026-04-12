def main():
    n = int(input())
    a = list(map(int, input().split()))
    if n % 2 == 0:
        dp = [[-10**18]*2, [-10**18]*2]
        dp[0][0] = 0
        for i in range(n):
            dp2 = [[-10**18]*2, [-10**18]*2]
            # 使う場合
            dp2[1][0] = max(dp2[1][0], dp[0][0]+a[i])
            dp2[1][1] = max(dp2[1][1], dp[0][1]+a[i])
            # 使わない場合
            dp2[0][1] = max(dp2[0][1], dp[0][0])
            # 更新
            dp2[0][0] = max(dp2[0][0], dp[1][0])
            dp2[0][1] = max(dp2[0][1], dp[1][1])
            dp = dp2
        print(max(dp[1][1], dp[0][0]))
        return
    dp = [[-10**18]*3, [-10**18]*3]
    dp[0][0] = 0
    for i in range(n):
        # 使う場合
        dp2 = [[-10**18]*3, [-10**18]*3]
        dp2[1][0] = max(dp2[1][0], dp[0][0]+a[i])
        dp2[1][1] = max(dp2[1][1], dp[0][1]+a[i])
        dp2[1][2] = max(dp2[1][2], dp[0][2]+a[i])
        # 使わない場合
        dp2[0][1] = max(dp2[0][1], dp[0][0])
        dp2[0][2] = max(dp2[0][2], dp[0][1])
        # 更新
        dp2[0][0] = max(dp2[0][0], dp[1][0])
        dp2[0][1] = max(dp2[0][1], dp[1][1])
        dp2[0][2] = max(dp2[0][2], dp[1][2])
        dp = dp2
    print(max(dp[1][2], dp[0][1]))


main()
