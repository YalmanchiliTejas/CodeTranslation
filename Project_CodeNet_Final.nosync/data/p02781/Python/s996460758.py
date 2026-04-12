N=input()
K=int(input())
l=len(N)
dp=[[0]+[1]*l]+[[0]*(l+1) for i in range(K)]
dp2=[[1]+[0]*l]+[[0]*(l+1) for i in range(K)]
for i,n in enumerate(N):
    n=int(n)
    for j in range(K):
        dp[j+1][i+1]=dp[j][i]*9+dp[j+1][i]+(dp2[j][i]*(n-1)+dp2[j+1][i] if n>0 else 0)
        dp2[j+1][i+1]=dp2[j][i] if n>0 else dp2[j+1][i]
print(dp[-1][-1]+dp2[-1][-1])