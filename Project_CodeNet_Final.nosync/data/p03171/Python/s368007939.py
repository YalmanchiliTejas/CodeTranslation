N = int(input())
a = list(map(int, input().split()))

S = [0] * (N+1)
for i in range(N):
    S[i+1] = S[i] + a[i]

dp = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    dp[i][i] = a[i]
for d in range(1, N):
    for i in range(N-d):
        dp[i][i+d] = max(a[i] + S[i+d+1] - S[i+1] - dp[i+1][i+d], a[i+d] + S[i+d] - S[i] - dp[i][i+d-1])
print(dp[0][N-1] * 2 - S[-1])
