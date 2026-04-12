
def resolve():
    MOD = 10**9+7
    K = input()
    D = int(input())
    N = len(K)

    # dp[keta][D][smaler]
    dp = [[[0]*2 for _ in range(D)] for _ in range(N+1)]
    dp[0][0][0] = 1

    for i in range(N):
        for d in range(D):
            # smaller=1 どの数字も使用できる
            for k in range(10):
                dp[i + 1][(d + k) % D][1] += dp[i][d][1]
                dp[i + 1][(d + k) % D][1] %= MOD

            # smaller=0 K[i]未満の数字のみ使用できる
            # 次の遷移は繰り上げが無いのでどの数字も使用できる。smaller = 1
            num = int(K[i])
            for k in range(num):
                dp[i + 1][(d + k) % D][1] += dp[i][d][0]
                dp[i + 1][(d + k) % D][1] %= MOD

            dp[i + 1][(d + num) % D][0] += dp[i][d][0]
            dp[i + 1][(d + num) % D][0] %= MOD


    print((dp[N][0][0] + dp[N][0][1] - 1) % MOD)


if __name__ == "__main__":
    resolve()