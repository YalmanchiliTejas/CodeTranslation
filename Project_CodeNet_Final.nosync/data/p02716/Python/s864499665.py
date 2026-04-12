N = int(input())
A = [0, 0]+list(map(int, input().split()))+[0, 0]
skip = N-2*(N//2)+1
dp = [[-10**18]*(skip+1) for _ in range(N+4)]

for i in range(2):
    for j in range(skip+1):
        dp[i][j] = 0

for i in range(2, N+4):
    for j in range(skip+1):
        dp[i][j] = max(dp[i][j], dp[i-2][j]+A[i])
        
        if i>=3 and j+1<=skip:
            dp[i][j+1] = max(dp[i][j+1], dp[i-3][j]+A[i])
        
        if i>=4 and j+2<=skip:
            dp[i][j+2] = max(dp[i][j+2], dp[i-4][j]+A[i])

print(dp[N+3][skip])