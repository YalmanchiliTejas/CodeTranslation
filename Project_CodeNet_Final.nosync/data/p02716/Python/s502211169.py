import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
K = 1+N%2
dp = [[-10**18]*(K+1) for _ in range(N+1)]
dp[0][0] = 0

for i in range(N):
    for j in range(K+1):
        if j+1<=K:
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j])
        
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+(A[i] if (i+j)%2==0 else 0))

print(dp[N][K])