N = int(input())
A = list(map(int,input().split()))

dp = [[-10**18 for i in range(N//2+1)] for j in range(2)]

dp[0][0] = 0
dp[1][1] = A[0]
dp[1][0] = 0

for i in range(2,N+1):
    high = min(N//2, i//2+10)
    low = max(0,i//2-10)
    for j in range(high,low,-1):
        dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1] + A[i-1])
print(dp[N%2][N//2])

