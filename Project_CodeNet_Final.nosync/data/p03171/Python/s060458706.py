n=int(input())
a=list(map(int,input().split()))
dp=[[0]*(n+2) for _ in range(n+2)]
# aiからajのX−Yの最大値
# [左端,右端)=[l,r)からの遷移    
# 左をとる[l+1,r)、右をとる[l,r−1)の2通り

for len in range(1,n+1):
  for i in range(n+1-len):
    j=i+len
    #先手の番
    if (n-len)%2==0:
      dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1])
    #後手の番
    else:
      dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1])
#print(dp)
print(dp[0][n])
    