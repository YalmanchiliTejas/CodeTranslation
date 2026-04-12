n=int(input())
l=len(str(n))
k=int(input())
dp=[[[0]*(k+1) for _ in range(2)] for _ in range(l+1)]
dp[0][1][0]=1
for pos in range(l):
  num=int(str(n)[pos])
  for i in range(10):
    if i==0:
      for count in range(k+1):
        if num==0:
          dp[pos+1][1][count]+=dp[pos][1][count]
          dp[pos+1][0][count]+=dp[pos][0][count]
        else:
          dp[pos+1][0][count]+=(dp[pos][0][count]+dp[pos][1][count])
    elif i<num:
      for count in range(k):
        dp[pos+1][0][count+1]+=(dp[pos][0][count]+dp[pos][1][count])
    elif i==num:
      for count in range(k):
        dp[pos+1][1][count+1]+=dp[pos][1][count]
        dp[pos+1][0][count+1]+=dp[pos][0][count]
    else:
      for count in range(k):
        dp[pos+1][0][count+1]+=dp[pos][0][count]
print(dp[l][0][k]+dp[l][1][k])