import sys
input = sys.stdin.readline

def func():
    N = int(input())
    A = [int(i) for i in input().split()]

    dp = [[0] * (N+1) for i in range(N+1)]
    for i in range(N):
        dp[i][i+1] = A[i]

    for s in range(2, N+1):
        for l in range(N-s+1):
            r = l + s
            dp[l][r] = max(A[l]-dp[l+1][r], A[r-1]-dp[l][r-1])
                            
    return dp[0][N]

print(func())