n=input()
k=int(input())
dp=[[(k+1)*[0]for _ in range(2)]for _ in range(len(n))]
#dp[i][flag][j]...i文字目までみて0以外がj個あるパターン数
#flag...True(n[])
dp[0][0][0]=1
dp[0][1][1]=1
dp[0][0][1]=int(n[0])-1
for i in range(1,len(n)):
  for j in range(k+1):dp[i][1][j]=dp[i-1][1][j]
  if n[i]!="0":dp[i][1]=[0]+dp[i][1][:k]
  for j in range(k+1):dp[i][0][j]=dp[i-1][0][j]
  for j in range(k):
    dp[i][0][j+1]+=dp[i-1][0][j]*9
    if n[i]!="0":
      dp[i][0][j+1]+=dp[i-1][1][j]*(int(n[i])-1)
      dp[i][0][j+1]+=dp[i-1][1][j+1]
print(dp[-1][0][-1]+dp[-1][1][-1])
#for i in dp:print(*i)