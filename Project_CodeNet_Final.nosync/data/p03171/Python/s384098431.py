N = int(input())
A = list(map(int, input().split()))

# dp[l][r]: 区間[l,r)のときのX-Y
dp = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

# 終局から遡る
# tは系列の長さ
for t in range(1, N+1):
    for l in range(N-t+1):
        r = t + l
        # 減った石の個数が偶数のとき、先手
        if (N - t) % 2 == 0:
            # 先手は直前の状態が大きい方
            # +X する
            dp[l][r] = max(dp[l + 1][r] + A[l], dp[l][r - 1] + A[r-1])
        else:
            # 先手は直前の状態が小さい方
            # -Y する
            dp[l][r] = min(dp[l + 1][r] - A[l], dp[l][r - 1] - A[r-1])

print(dp[0][N])