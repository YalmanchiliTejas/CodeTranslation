n=input()
k=int(input())
m=len(n)

dp=[[[0]*2 for _ in range(4)] for _ in range(m+1)]

dp[0][0][0]=1
for i in range(m):
  keta=int(n[i])
  for j in range(3):
    dp[i+1][j+1][1]+=9*dp[i][j][1]
    dp[i+1][j][1]+=dp[i][j][1]
    
    if keta>0:
      dp[i+1][j+1][1]+=dp[i][j][0]*(keta-1)
      dp[i+1][j][1]+=dp[i][j][0]
      dp[i+1][j+1][0]+=dp[i][j][0]
    else:
      dp[i+1][j][0]+=dp[i][j][0]
      
  dp[i+1][3][1]+=dp[i][3][1]
  dp[i+1][3][keta>0]+=dp[i][3][0]
print(dp[m][k][0]+dp[m][k][1])