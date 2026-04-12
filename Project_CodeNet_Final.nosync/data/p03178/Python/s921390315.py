mod=10**9+7
k=input()
d=int(input())

dp=[[[0]*2 for i in range(d)] for j in range(len(k)+1)]
dp[0][0][0]=1

for i in range(len(k)):
  x=int(k[i])
  for j in range(d):
    dp[i+1][(j+x)%d][0]+=dp[i][j][0]
    dp[i+1][(j+x)%d][0]%=mod
    for z in range(10):
      dp[i+1][(j+z)%d][1]+=dp[i][j][1]
      dp[i+1][(j+z)%d][1]%=mod
    
    for y in range(x):
      dp[i+1][(j+y)%d][1]+=dp[i][j][0]
      dp[i+1][(j+y)%d][1]%=mod
      

print((dp[-1][0][0]+dp[-1][0][1]-1)%mod)