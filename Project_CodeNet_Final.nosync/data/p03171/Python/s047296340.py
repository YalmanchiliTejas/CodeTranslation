
def resolve():
    N = int(input())
    A = list(map(int, input().split()))

    dp = [[0] * (N+1) for _ in range(N+1)]
    # 左側をとる: 区間 [i+1,j)[i+1,j) に遷移
    # 右側をとる: 区間 [i,j−1)[i,j−1) に遷移
    for L in range(1, N + 1):
        i = 0
        while i + L <= N:
            j = i + L
            # 先手番
            if (N - L) % 2 == 0:
                dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j - 1])
            # 後手番
            else:
                dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j - 1])
            i += 1

    print(dp[0][N])


if __name__ == "__main__":
    resolve()