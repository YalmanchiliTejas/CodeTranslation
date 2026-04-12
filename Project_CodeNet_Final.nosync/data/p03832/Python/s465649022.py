N,A,B,C,D=map(int,input().split())
mod=10**9+7

factorial=[1]
for i in range(1,1001):
    factorial.append((factorial[-1]*i)%mod)

inverse=[pow(factorial[i],mod-2,mod) for i in range(1001)]

Inverse=[[1] for i in range(1001)]
for i in range(1001):
    for j in range(1,1001):
        Inverse[i].append((Inverse[i][-1]*inverse[i])%mod)

dp=[{i:0 for i in range(A-1,B+1)} for j in range(N+1)]

for i in range(A-1,B+1):
    dp[0][i]=1


for i in range(1,N+1):
    for j in range(A,B+1):
        dp[i][j]=dp[i][j-1]+factorial[i]*sum(dp[i-k*j][j-1]*Inverse[j][k]*inverse[k]*inverse[i-j*k] for k in range(C,min(D,i//j)+1))
        dp[i][j]%=mod

print(dp[N][B])