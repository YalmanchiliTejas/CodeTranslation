S=list(input())
n=len(S)
for i in range(n):
  S[i]=int(S[i])
k=int(input())
dp0=[[0]*(n+1) for i in range(k+1)]
dp0[0][0]=1
s=0
for i in range(n):
  if S[i]!=0:
    s=s+1
    if s==k+1:
      break
    dp0[s][i+1]=1
  else:
    dp0[s][i+1]=1
dp1=[[0]*(n+1) for i in range(k+1)]
for i in range(1,n+1):
  if dp0[0][i]==0:
    dp1[0][i]=1
for i in range(1,k+1):
  for j in range(1,n+1):
    if S[j-1]==0:
      dp1[i][j]=dp0[i-1][j-1]*0+dp0[i][j-1]*0+dp1[i-1][j-1]*9+dp1[i][j-1]
    else:
      dp1[i][j]=dp0[i-1][j-1]*(S[j-1]-1)+dp0[i][j-1]+dp1[i-1][j-1]*9+dp1[i][j-1]
print(dp0[-1][-1]+dp1[-1][-1])