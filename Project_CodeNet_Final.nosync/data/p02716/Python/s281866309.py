import sys

n = int(input())
A = [int(_) for _ in input().split()]

if n == 1 or n == 2 or n == 3:
    print(max(A))
    sys.exit()

dp = [[0, 0] for j in range(n)]
M = - float('inf')
for i in range(4):
    M = max(M, A[i])
    dp[i][0] = M
dp[2][1] = dp[0][0] + A[2]
dp[3][1] = max(dp[1][0] + A[3], dp[2][1])

for i in range(4, n):
    for j in range(2):
        if i % 2 == 0 and j == 1:
            dp[i][j] = dp[i-2][1] + A[i]
        elif i % 2 == 0 and j == 0:
            dp[i][j] = max(dp[i-2][0] + A[i], dp[i-1][1])
        elif i % 2 == 1 and j == 1:
            dp[i][j] = max(dp[i-2][1] + A[i], dp[i-1][1])
        else:
            dp[i][j] = max(dp[i-2][0] + A[i], dp[i-1][0])

print(dp[n-1][(n+1)%2])