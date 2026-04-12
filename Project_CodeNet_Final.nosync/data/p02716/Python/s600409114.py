n=int(input())
a=list(map(int,input().split()))
if n<=3:print(max(a));exit()
if n&1:
  dp=[3*[-(10**20)]for _ in range(n)]
  dp[0][0]=a[0]
  for i in range(1,n):
    if i%2==0:
      dp[i][0]=dp[i-2][0]+a[i]
      if i>=3:dp[i][2]=max(dp[i-2][2]+a[i],dp[i-3][1]+a[i])
      else:dp[i][2]=a[i]
    else:
      if i>=3:dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i])
      else:dp[i][1]=a[i]
  print(max(dp[-1][2],dp[-2][1],dp[-3][0]))
else:
  b=[a[0]]
  c=[a[1]]
  for i in range(2,n):
    if i%2==0:b.append(b[-1]+a[i])
    else:c.append(c[-1]+a[i])
  ans=max(b[-1],c[-1])
  for i in range(n//2-1):
    ans=max(ans,b[i]+c[-1]-c[i])
  print(ans)
