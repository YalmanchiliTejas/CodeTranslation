import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
dp = [[-10**18]*3 for _ in range(N)]
dp[0][0] = A[0]
dp[1][1] = A[1]

if N>=3:
    dp[2][2] = A[2]

for i in range(2, N):
    dp[i][0] = dp[i-2][0]+A[i]
    dp[i][1] = max(dp[i][1], dp[i-2][1]+A[i])
    
    if i>=3:
        dp[i][1] = max(dp[i][1], dp[i-3][0]+A[i])
    
    dp[i][2] = max(dp[i][2], dp[i-2][2]+A[i])
    
    if i>=3:
        dp[i][2] = max(dp[i][2], dp[i-3][1]+A[i])
    
    if i>=4:
        dp[i][2] = max(dp[i][2], dp[i-4][0]+A[i])

if N%2==0:
    print(max(dp[N-2][0], dp[N-1][1]))
else:
    print(max(dp[N-3][0], dp[N-2][1], dp[N-1][2]))