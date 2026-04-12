n=input()
k=int(input())
dp0=[[0]*(k+1) for _ in range(len(n))]
dp1=[[0]*(k+1) for _ in range(len(n))]
for i in range(len(n)):
  dp0[i][0]=1
if len(n)==1:
  dp0[0][1]=int(n)
else:
  dp0[0][1]=int(n[0])-1
  dp1[0][1]=1
  for i in range(1,len(n)):
    num=int(n[i])
    for j in range(k):
      dp0[i][j+1]=dp0[i-1][j+1]+dp0[i-1][j]*9+dp1[i-1][j]*max(num-1,0)
    if num==0:
      for j in range(1,k+1):
        dp1[i][j]=dp1[i-1][j]
    else:
      for j in range(k):
        dp1[i][j+1]=dp1[i-1][j]
        dp0[i][j+1]+=dp1[i-1][j+1]
      dp1[i][1]=0
print(dp0[len(n)-1][k]+dp1[len(n)-1][k])