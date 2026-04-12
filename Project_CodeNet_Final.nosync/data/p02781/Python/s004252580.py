n=input()
k=int(input())
lenn=len(n)
dp=[[[0]*2 for i in range(k+1)] for j in range(lenn)]
dp[0][1][1]+=int(n[0])-1
dp[0][0][1]+=1
dp[0][1][0]+=1
for i in range(1,lenn):
  keta=int(n[i])
  for j in range(k):
    dp[i][j+1][1]+=dp[i-1][j][1]*9
    dp[i][j][1]+=dp[i-1][j][1]
    if keta>0:
      dp[i][j+1][1]+=dp[i-1][j][0]*(keta-1)
      dp[i][j+1][0]+=dp[i-1][j][0]
      dp[i][j][1]+=dp[i-1][j][0]
    else:
      dp[i][j][0]+=dp[i-1][j][0]
  dp[i][k][1]+=dp[i-1][k][1]
  if keta>0:
    dp[i][k][1]+=dp[i-1][k][0]
  else:
    dp[i][k][0]+=dp[i-1][k][0]
print(dp[lenn-1][k][1]+dp[lenn-1][k][0])