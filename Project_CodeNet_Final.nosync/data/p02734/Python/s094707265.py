def main():
    MOD = 998244353
    N, S = list(map(int, input().split()))
    A = list(map(int, input().split()))
    dp = [[0] * (S + 1) for _ in range(N + 1)]
    dp[0][0] = 1
    for n in range(1, N + 1):
        a = A[n - 1]
        dp[n][0] = dp[n - 1][0] + 1
        for s in range(1, S):
            # dp[n][s]: n個目で和がちょうどsになるインデックスの組における
            #           L のパターン数
            v = dp[n - 1][s]
            if s - a >= 0:
                v += dp[n - 1][s - a]
            dp[n][s] = v % MOD
        if S - a >= 0:
            # n個目で和がちょうどSになる時にRのパターン数をかけておく
            dp[n][S] = dp[n - 1][S - a] * (N - n + 1) % MOD
    print(sum(dp[n][S] for n in range(N + 1)) % MOD)


if __name__ == '__main__':
    main()