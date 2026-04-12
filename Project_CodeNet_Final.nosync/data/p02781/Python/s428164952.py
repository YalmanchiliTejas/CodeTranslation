n=int(input())
m=len(str(n))
k=int(input())
N=[int(i) for i in str(n)]
dp0=[[0]*(k+1) for _ in range(m+1)]
dp1=[[0]*(k+1) for _ in range(m+1)]
dp1[0][0]=1
for i in range(m):
  for j in range(k+1):
    dp1[i+1][j]+=dp1[i][j]*(N[i]==0)
    dp0[i+1][j]+=dp0[i][j]+dp1[i][j]*(N[i]>0)
    if j<k:
      dp1[i+1][j+1]+=dp1[i][j]*(N[i]>0)
      dp0[i+1][j+1]+=dp0[i][j]*9+dp1[i][j]*max(0,N[i]-1)
print(dp1[m][k]+dp0[m][k])