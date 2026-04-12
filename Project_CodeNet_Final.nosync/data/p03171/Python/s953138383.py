N = int(input())
A = list(map(int, input().split()))

dp = [[0 for _ in range(N)] for _ in range(N)]

for index in range(N):
    dp[index][index] = A[index]

for i in range(N - 2, -1, -1):
    for j in range(i + 1, N):
        l = A[i] - dp[i+1][j]
        r = A[j] - dp[i][j-1]
        dp[i][j] = max(l,r)

print(dp[0][N-1])
