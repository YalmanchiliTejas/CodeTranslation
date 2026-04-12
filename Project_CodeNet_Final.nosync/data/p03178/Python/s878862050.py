N=input()
D=int(input())

s = len(N)
mod=10**9+7
#[2][D][s]
dp=[[[0]*(s+1) for i in range(D)] for i in range(2)]
dp[0][0][0]=1
for i in range(s):
    for j in range(D):
        for k in range(10):
            dp[1][(j+k)%D][i+1]+=dp[1][j][i]
            dp[1][(j+k)%D][i+1]%=mod
        for k in range(int(N[i])):
            dp[1][(j+k)%D][i+1]+=dp[0][j][i]
            dp[1][(j+k)%D][i+1]%=mod
        dp[0][(j+int(N[i]))%D][i+1]+=dp[0][j][i]
        dp[0][(j+int(N[i]))%D][i+1]%=mod
print((dp[0][0][s]+dp[1][0][s]-1)%mod)
