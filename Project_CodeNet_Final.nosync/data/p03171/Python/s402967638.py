N = int(input())
A = list(map(int,input().split()))
dp = [[0 for j in range(N)] for i in range(N)]
if N%2==0:
    for i in range(N):
        dp[i][i] = -A[i]
    for k in range(1,N):
        for i in range(N-1):
            if i+k<N:
                if k%2==0:
                    dp[i][i+k]= min(-A[i]+dp[i+1][i+k],-A[i+k]+dp[i][i+k-1])
                else:
                    dp[i][i+k] = max(A[i]+dp[i+1][i+k],A[i+k]+dp[i][i+k-1])
else:
    for i in range(N):
        dp[i][i] = A[i]
    for k in range(1,N):
        for i in range(N-1):
            if i+k<N:
                if k%2==0:
                    dp[i][i+k]= max(A[i]+dp[i+1][i+k],A[i+k]+dp[i][i+k-1])
                else:
                    dp[i][i+k] = min(-A[i]+dp[i+1][i+k],-A[i+k]+dp[i][i+k-1])
print(dp[0][N-1])                