n=input()
k=int(input())
lenn=len(n)
dp=[[[0]*2 for i in range(k+1)] for j in range(lenn)]
for i in range(int(n[0])+1):
  keta=int(n[0])
  if i<keta:
    if i==0:
      dp[0][0][1]+=1
    else:
      dp[0][1][1]+=1
  elif i==keta:
    dp[0][1][0]+=1
for i in range(1,lenn):
  keta=int(n[i])
  for l in range(10):
    for j in range(k):
      if l>0:
        dp[i][j+1][1]+=dp[i-1][j][1]
      else:
        dp[i][j][1]+=dp[i-1][j][1]
      if l<keta:
        if l>0:
          dp[i][j+1][1]+=dp[i-1][j][0]
        else:
          dp[i][j][1]+=dp[i-1][j][0]
      elif l==keta:
        if keta==0:
          dp[i][j][0]+=dp[i-1][j][0]
        else:
          dp[i][j+1][0]+=dp[i-1][j][0]
  if keta==0:
    dp[i][k][0]+=dp[i-1][k][0]
  else:
    dp[i][k][1]+=dp[i-1][k][0]
  dp[i][k][1]+=dp[i-1][k][1]
print(dp[lenn-1][k][0]+dp[lenn-1][k][1])