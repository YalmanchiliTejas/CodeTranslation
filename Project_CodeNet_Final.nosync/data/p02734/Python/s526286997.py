def main():
    import sys
    input = sys.stdin.readline

    N, S = map(int, input().split())
    A = list(map(int, input().split()))
    mod = 998244353

    dp = [[0] * (S+1) for _ in range(N+1)]
    dp[0][0] = 1
    for i in range(N):
        a = A[i]
        for j in range(S+1):
            dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod
            if j+a <= S:
                tmp = 1
                if j == 0:
                    tmp *= (i+1)
                if j+a == S:
                    tmp *= (N-i)
                dp[i+1][j+a] = (dp[i+1][j+a] + (dp[i][j] * tmp)%mod)%mod
    print(dp[-1][S])


if __name__ == '__main__':
    main()
