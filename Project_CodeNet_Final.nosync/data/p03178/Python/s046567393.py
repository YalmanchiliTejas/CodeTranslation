K=input()
N=len(K)
D=int(input())
mod=10**9+7

dp=[[[0 for i in range(0,2)] for j in range(0,D)] for k in range(0,N+1)]

dp[N][0][0]=1
dp[N][0][1]=1

for _ in range(0,N):
    i=N-_-1
    for j in range(0,D):
        ans=0
        for k in range(0,10):
            ans+=dp[i+1][(j+k)%D][0]

        dp[i][j][0]=ans%mod

        ans=0
        for k in range(0,int(K[i])):
            ans+=dp[i+1][(j+k)%D][0]

        ans+=dp[i+1][(j+int(K[i]))%D][1]

        dp[i][j][1]=ans%mod

print((dp[0][0][1]-1)%mod)