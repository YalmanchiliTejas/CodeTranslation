import sys
input = sys.stdin.readline

def func():
    N = int(input())
    A = [int(i) for i in input().split()]

    dp = [[0] * (N+1) for i in range(N+1)]
    if (N - 1) % 2 == 0:
        fl = 1
    else:
        fl = -1
    for i in range(N):
        dp[i][i+1] = fl * A[i]

    for s in range(2, N+1):
        for l in range(N-s+1):
            r = l + s
            if (N - s) % 2 == 0:
                dp[l][r] = max(dp[l+1][r]+A[l], dp[l][r-1]+A[r-1])
                continue
            dp[l][r] = min(dp[l+1][r]-A[l], dp[l][r-1]-A[r-1])
                
    return dp[0][N]

print(func())