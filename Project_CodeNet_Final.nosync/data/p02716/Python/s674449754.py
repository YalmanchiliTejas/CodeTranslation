N, *A = map(int, open(0).read().split())

dp = [[-10 ** 10] * 3 for _ in range(N + 1)]
dp[0] = [0] * 3
dp[1][0] = A[0]
dp[2][1] = A[1]
for i in range(2, N):
    dp[i + 1][0] = dp[i - 1][0] + A[i]
    dp[i + 1][1] = max(dp[i - 1][1], dp[i - 2][0]) + A[i]
    dp[i + 1][2] = max(dp[i - 1][2], dp[i - 2][1], dp[i - 3][0]) + A[i]

if N % 2 == 1:
    print(max(dp[-3][0], dp[-2][1], dp[-1][2]))
else:
    print(max(dp[-2][0], dp[-1][1]))

