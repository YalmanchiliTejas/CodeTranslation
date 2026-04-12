def main():
    MOD = 998244353

    N, S = map(int, input().split())
    *A, = map(int, input().split())

    dp = [0] * (S + 1)
    ans = 0
    for x in A:
        dp[0] += 1
        for j in range(S, x - 1, -1):
            dp[j] = (dp[j] + dp[j - x]) % MOD
        ans = (ans + dp[S]) % MOD
    print(ans)


if __name__ == '__main__':
    main()
