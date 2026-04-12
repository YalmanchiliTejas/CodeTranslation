# coding: utf-8
# Your code here!
N=int(input())
K=int(input())

n=(str(N))
dp=[[0]*(K+1) for i in range(len(n))]
dp[0][0]=1
dp[0][1]=int(n[0])


count=1
for i in range(len(n)-1):
    dp[i+1][0]+=dp[i][0]
    dp[i+1][1]+=(dp[i][0])*9
    #print(count)
    for j in range(1,K):
        dp[i+1][j]+=dp[i][j]
        dp[i+1][j+1]+=max((dp[i][j]-1)*9+int(n[i+1]),0) if j==count else dp[i][j]*9
    if int(n[i+1])!=0:
        count+=1
    dp[i+1][K]+=dp[i][K]
    
print(dp[-1][-1])
