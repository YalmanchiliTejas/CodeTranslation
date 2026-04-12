
MOD = 998244353
def resolve():
    # 多項式 解
    N, S = map(int, input().split())
    A = list(map(int, input().split()))
    dp = [[0] * (S + 1) for _ in range(N + 1)]
    dp[0][0] = 1

    ans = 0
    for i in range(N):
        dp[i + 1][0] = dp[i][0] + 1
        for j in range(1, S + 1):
            if j - A[i] >= 0:
                dp[i + 1][j] += dp[i][j - A[i]]
            dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % MOD
        ans = (ans + dp[i + 1][-1]) % MOD
        ans %= MOD
    print(ans)


if __name__ == "__main__":
    resolve()
