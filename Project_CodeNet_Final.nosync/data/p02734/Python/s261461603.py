def main():
    N, S = map(int, input().split())
    A = tuple(map(int, input().split()))

    MOD = 998244353

    dp = [[0]*(S+1) for _ in range(N+1)]
    dp[0][0] = 1

    # dp[i][j] : i番目の要素が右端である区間のうち，和がjになる整数列を持つ区間の個数
    for i, a in enumerate(A):            
        for j in range(S+1):
            if j == a:
                dp[i+1][j] += dp[i][j] + i + 1
                dp[i+1][j] %= MOD
            elif j > a:
                dp[i+1][j] += dp[i][j] + dp[i][j-a]
                dp[i+1][j] %= MOD
            else:
                dp[i+1][j] += dp[i][j]
                dp[i+1][j] %= MOD

            
    ans = sum([dp[i][S] for i in range(N+1)])
    ans %= MOD
    print(ans)

if __name__ == "__main__":
    main()