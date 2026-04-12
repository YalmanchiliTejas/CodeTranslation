Nstr=input()
N=int(Nstr)
K=int(input())
x=len(Nstr)
dp0=[[0]*(K+1) for i in range(x+1)]
dp1=[[0]*(K+1) for i in range(x+1)]

dp1[0][0]=1

for i in range(1,x+1):
  dp0[i][0]=dp0[i-1][0]+dp1[i-1][0]
  for j in range(1,K+1):
    if Nstr[i-1]!='0':
      dp1[i][j]=dp1[i-1][j-1]
      dp0[i][j]+=(dp1[i-1][j-1]*(int(Nstr[i-1])-1)+dp1[i-1][j])
    else:
      dp1[i][j]=dp1[i-1][j]
    dp0[i][j]+=(dp0[i-1][j]+dp0[i-1][j-1]*9)

    
  '''  
  if Nstr[i-1]!='0':
    for j in range(1,K+1):
      dp1[i][j]=dp1[i-1][j-1]
      dp0[i][j]+=(dp1[i-1][j-1]*(int(Nstr[i-1])-1)+dp1[i-1][j])
  else:
    for j in range(1,K+1):
      dp1[i][j]=dp1[i-1][j]
  for j in range(1,K+1):
    dp0[i][j]+=(dp0[i-1][j]+dp0[i-1][j-1]*9)
  '''
print(dp0[x][K]+dp1[x][K])