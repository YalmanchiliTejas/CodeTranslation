N = int(input())
A = list(map(int,input().split()))

dp = [[None for j in range(N-i)] for i in range(N)]

for i,a in enumerate(A):
    dp[i][N-i-1] = a * (1 if N%2 else -1)

for k in range(N-2,-1,-1):
    for l in range(k+1):
        r = k-l
        if k%2:
            dp[l][r] = min(dp[l+1][r] - A[l], dp[l][r+1] - A[-1-r])
        else:
            dp[l][r] = max(dp[l+1][r] + A[l], dp[l][r+1] + A[-1-r])

print(dp[0][0])