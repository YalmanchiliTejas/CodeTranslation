mod=10**9+7
n=input()
d=int(input())
l=len(n)
dp=[[[0]*d for _ in range(2)] for _ in range(l+1)]
dp[0][0][0]=1
for i in range(l):
  for j in range(10):
    for k in range(d):
      if j==int(n[i]):
        dp[i+1][0][(k+j)%d]+=dp[i][0][k]
        dp[i+1][1][(k+j)%d]+=dp[i][1][k]
      elif j<int(n[i]):
        dp[i+1][1][(k+j)%d]+=dp[i][0][k]+dp[i][1][k]
      elif j>int(n[i]):
        dp[i+1][1][(k+j)%d]+=dp[i][1][k]
      dp[i+1][0][k]%=mod
      dp[i+1][1][k]%=mod
print((dp[-1][0][0]+dp[-1][1][0]-1)%mod)