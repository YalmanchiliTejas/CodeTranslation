def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    dp = [[0]*(N+1) for _ in range(N+1)]

    for w in range(1, N+1):
        for le in range(N):
            ri = le + w
            if N < ri:
                break
            if N % 2 == w % 2:
                # 先手番
                dp[le][ri] = max(dp[le + 1][ri] + A[le],
                                 dp[le][ri - 1] + A[ri - 1])
            else:
                # 後手番
                dp[le][ri] = min(dp[le + 1][ri] - A[le],
                                 dp[le][ri - 1] - A[ri - 1])

    print(dp[0][N])


if __name__ == '__main__':
    main()
