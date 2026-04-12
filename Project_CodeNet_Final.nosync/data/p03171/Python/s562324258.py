N = int(input())
A = [int(i) for i in input().split()]

dp = [[0 for j in range(N+1)] for i in range(N+1)]

for l in range(1, N+1):
    for i in range(N+1-l):
        j = i+l

        if (N-l) % 2 == 0:
            dp[i][j] = max(dp[i+1][j]+A[i], dp[i][j-1]+A[j-1])
        else:
            dp[i][j] = min(dp[i+1][j]-A[i], dp[i][j-1]-A[j-1])

# print(dp)
print(dp[0][N])
