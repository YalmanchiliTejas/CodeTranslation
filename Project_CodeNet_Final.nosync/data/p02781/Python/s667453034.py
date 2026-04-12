n=input()
K=int(input())
ns=len(n)
dp=[[[0]*(5) for _ in range(2)]for _ in range(ns+1)]
dp[0][0][0]=1
for i in range(ns):
    for k in range(K+1):
        dp[i+1][1][k+1]+=dp[i][1][k]*9
        dp[i+1][1][k]+=dp[i][1][k]
        if int(n[i])>0:
            dp[i+1][1][k+1]+=dp[i][0][k]*(int(n[i])-1)
            dp[i+1][1][k]+=dp[i][0][k]
            dp[i+1][0][k+1]+=dp[i][0][k]
        else:
            dp[i+1][0][k]+=dp[i][0][k]

#print(dp)
print(dp[ns][0][K]+dp[ns][1][K])