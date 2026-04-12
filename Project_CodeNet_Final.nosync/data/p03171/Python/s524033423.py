n = int(input())
A = [int(i) for i in input().split()]

DP = [[0] * n for i in range(n)]
if n % 2 == 1:
    for i in range(n):
        DP[i][i] = A[i]
else:
    for i in range(n):
        DP[i][i] = -A[i]

for i in range(1, n):
    for l in range(n-i):
        if (n - i) % 2 == 1:
            DP[l][l+i] = max(DP[l+1][l+i] + A[l], DP[l][l+i-1] + A[l+i])
        else:
            DP[l][l+i] = min(DP[l+1][l+i] - A[l], DP[l][l+i-1] - A[l+i])

print(DP[0][n-1])