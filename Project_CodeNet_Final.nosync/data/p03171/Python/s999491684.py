N = int(input())
A = list(map(int, input().split()))

dp = [[0]*(N+1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(N-i+1):
        dp[i][j] = max(-dp[i-1][j] + A[j+i-1], -dp[i-1][j+1] + A[j])
print(dp[-1][0])