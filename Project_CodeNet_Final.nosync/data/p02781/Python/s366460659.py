N=int(input())
K=int(input())

S=str(N)
l=len(S)

dp=[[[0]*4 for __ in range(2)] for _ in range(l)]
dp[0][0][1]=1
dp[0][1][0]=1
dp[0][1][1]=int(S[0])-1

for i in range(1, l):
  if S[i]=='0':
    for k in range(1, 4):
      dp[i][0][k]=dp[i-1][0][k]
      dp[i][1][k]=dp[i-1][1][k]+dp[i-1][1][k-1]*9
    dp[i][1][0]=dp[i-1][1][0]
  else:
    dp[i][0][2]=dp[i-1][0][1]
    dp[i][0][3]=dp[i-1][0][2]
    dp[i][1][0]=1
    dp[i][1][1]=dp[i-1][1][1]+dp[i-1][1][0]*9+dp[i-1][0][1]
    dp[i][1][2]=dp[i-1][1][2]+dp[i-1][1][1]*9+dp[i-1][0][2]+dp[i-1][0][1]*(int(S[i])-1)
    dp[i][1][3]=dp[i-1][1][3]+dp[i-1][1][2]*9+dp[i-1][0][3]+dp[i-1][0][2]*(int(S[i])-1)
    
print(dp[-1][0][K]+dp[-1][1][K])