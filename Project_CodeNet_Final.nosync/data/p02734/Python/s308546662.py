
def resolve():
    MOD = 998244353
    N, S = map(int, input().split())
    A = list(map(int, input().split()))

    dp = [[0] * (S + 1) for _ in range(N + 1)]
    dp[0][0] = 1

    for i in range(N):
        dp[i + 1][0] += 1
        for s in range(S + 1):
            dp[i + 1][s] += dp[i][s]
            dp[i + 1][s] %= MOD
            if s + A[i] <= S:
                dp[i + 1][s + A[i]] += dp[i][s]
                dp[i + 1][s + A[i]] %= MOD
    ans = 0
    for i in range(1, N + 1):
        ans += dp[i][S]
        ans %= MOD
    print(ans)


if __name__ == "__main__":
    resolve()
