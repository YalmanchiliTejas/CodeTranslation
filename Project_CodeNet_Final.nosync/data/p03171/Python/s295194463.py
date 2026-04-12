n=int(input())
a=list(map(int,input().split()))
# 元の数列から連続する区間[i,j) を抜き出した状態から、
# 最善を尽くした場合のX-Yの最大値
dp=[[0]*(n+1) for i in range(n+1)]

for i in range(n + 1):
    dp[i][i] = 0

for length in range(1,n+1):
  for i in range(n+1):
    j=length+i
    if j<=i or j>n:continue
    if (n-length)%2==0:
      # 先手
      dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1])
    else:
      # 後手
      dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1])

print(dp[0][n])