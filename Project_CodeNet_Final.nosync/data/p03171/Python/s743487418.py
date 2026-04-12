n = int(input())
*A, = map(int, input().split())
DP = [[0 for j in range(n+1)] for i in range(n+1)]
for l in range(1, n+1):
    for i in range(n-l+1):
        DP[i][i+l] = max(A[i]-DP[i+1][i+l], A[i+l-1]-DP[i][i+l-1])
print(DP[0][n])
