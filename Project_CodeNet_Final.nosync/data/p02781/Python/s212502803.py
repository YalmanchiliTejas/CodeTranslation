N=input()
keta=len(N)
K=int(input())

dp=[[[0 for i in range(K+1)] for j in range(2)] for k in range(keta)]

def getMiman(X):
  if X>0:
    return X-1
  else:
    return 0

x0=int(N[0])
dp[0][0][0]=0
dp[0][1][0]=1
dp[0][0][1]=1
dp[0][1][1]=getMiman(x0)

for i in range(1,keta):
  x=int(N[i])
  dp[i][0][0]=0
  dp[i][1][0]=1
  for j in range(1,K+1):
    dp[i][0][j]=dp[i-1][0][j-1]*(x!=0)+dp[i-1][0][j]*(x==0)
    dp[i][1][j]=dp[i-1][0][j-1]*getMiman(x)+dp[i-1][0][j]*(x!=0)+dp[i-1][1][j-1]*9+dp[i-1][1][j]*1
  
print(dp[keta-1][0][K]+dp[keta-1][1][K])  
