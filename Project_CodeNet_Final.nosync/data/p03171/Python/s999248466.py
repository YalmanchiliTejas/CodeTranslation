N=int(input())
A=[int(i) for i in input().split()]
S=[0]*(N+1)
for i in range(1,N+1):
    S[i]=S[i-1]+A[i-1]
dp=[[0]*N for i in range(N)]
for i in range(N):
    dp[i][i]=A[i]
for k in range(1,N):
    for i in range(N-k):
        j=i+k
        dp[i][j]=max(S[j]-S[i]-dp[i][j-1]+A[j],S[j+1]-S[i+1]-dp[i+1][j]+A[i])
print(2*dp[0][N-1]-S[N])