s=input()
n=len(s)
K=int(input())
dp=[[[0,0] for _ in range(K+1)] for _ in range(n+1)]
dp[0][0][0]=1
r=range
for i in r(n):
  nd=int(s[i])
  for j in r(K+1):
    for k in r(2):
      for d in r(10):
        ni,nj,nk=i+1,j,k
        if d: nj+=1
        if nj>K: continue
        if k<1:
          if d>nd: continue
          if d<nd: nk=1
        dp[ni][nj][nk]+=dp[i][j][k]
print(dp[n][K][0]+dp[n][K][1])