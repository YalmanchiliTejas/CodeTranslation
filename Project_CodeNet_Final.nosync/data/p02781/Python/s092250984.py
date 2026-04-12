N=str(input())
n=len(N)
K=int(input())
dp0=[[0]*(K+1) for _ in range(n+1)]
dp1=[[0]*(K+1) for _ in range(n+1)]
for l in range(1,n+1):
  dp0[l][0]=1
dp1[0][0]=1
for i in range(n):
  for j in range(K):
    if N[i]=='0':
      dp0[i+1][j+1]=9*dp0[i][j]+dp0[i][j+1]
      dp1[i+1][j+1]=dp1[i][j+1]
    else:
      dp0[i+1][j+1]=dp0[i][j]*9+dp0[i][j+1]+dp1[i][j]*(int(N[i])-1)+dp1[i][j+1]
      dp1[i+1][j+1]=dp1[i][j]
print(dp0[n][K]+dp1[n][K])