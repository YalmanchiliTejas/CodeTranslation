n,s=map(int,input().split())
a=list(map(int,input().split()))
mod=998244353
dp0=[[0 for i in range(s+1)] for j in range(n+1)]
dp1=[[0 for i in range(s+1)] for j in range(n+1)]
dp2=[[0 for i in range(s+1)] for j in range(n+1)]
dp0[0][0]=1
for i in range(n):
  for j in range(s+1):
    if j>=a[i]:
      dp1[i+1][j]=(dp0[i][j-a[i]]+dp1[i][j-a[i]]+dp0[i][j]+dp1[i][j])%mod
      dp2[i+1][j]=(dp0[i][j-a[i]]+dp1[i][j-a[i]]+dp0[i][j]+dp1[i][j]+dp2[i][j])%mod
    else:
      dp0[i+1][j]=dp0[i][j]%mod
      dp1[i+1][j]=(dp0[i][j]+dp1[i][j])%mod
      dp2[i+1][j]=(dp0[i][j]+dp1[i][j]+dp2[i][j])%mod
print(dp2[n][s])