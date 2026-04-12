n=input()
k=int(input())
dp=[[[0]*(k+2) for _ in range(2)] for _ in range(len(n)+1)]
dp[0][0][0]=1
for i,c in enumerate(n):
  c=int(c)
  for j in range(2):
    for l in range(k+1):
      for nxt in range(10*j or c+1):
        dp[i+1][j or nxt<c][l+(nxt>0)]+=dp[i][j][l]
print(dp[-1][1][k]+dp[-1][0][k])