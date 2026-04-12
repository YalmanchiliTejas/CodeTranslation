mod=10**9+7
n=input()
D=int(input())
N=len(n)+1
dp=[[[0 for i in range(2)] for j in range(D)] for k in range(len(n)+1)]
dp[0][0][0]=1
for a in range(N-1):
  x=int(n[a])
  for b in range(D):
    for d in range(10):
      if d<x:
        dp[a+1][(b+d)%D][1]+=dp[a][b][0]+dp[a][b][1]
      elif d==x:
        dp[a+1][(b+d)%D][0]+=dp[a][b][0]
        dp[a+1][(b+d)%D][1]+=dp[a][b][1]
      else:
        dp[a+1][(b+d)%D][1]+=dp[a][b][1]
      dp[a+1][(b+d)%D][1]%=mod
      dp[a+1][(b+d)%D][0]%=mod
ans=sum(dp[-1][0])
print((ans-1)%mod)