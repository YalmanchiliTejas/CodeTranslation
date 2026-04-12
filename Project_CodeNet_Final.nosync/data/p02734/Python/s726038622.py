MOD = 998244353


def main():
    N, S = (int(i) for i in input().split())
    A = [int(i) for i in input().split()]
    dp = [[0]*(S+1) for _ in range(N+1)]
    dp[0][0] = 1
    for i in range(N):
        dp[i+1][0] += 1
        for j in range(S+1):
            dp[i+1][j] += dp[i][j]
            dp[i+1][j] %= MOD
            if j + A[i] <= S:
                dp[i+1][j+A[i]] += dp[i][j]
                dp[i+1][j+A[i]] %= MOD
    ans = 0
    for i in range(N+1):
        ans += dp[i][S]
        ans %= MOD
    print(ans % MOD)


if __name__ == '__main__':
    main()
