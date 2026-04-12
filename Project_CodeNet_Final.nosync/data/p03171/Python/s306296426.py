n=int(input())
A=list(map(int,input().split()))

dp=[[-10**12]*(n+1) for i in range(n+1)]
#dp[i][j]:=A[j:j+i+1]
if n%2==0:
  for i in range(n):
    dp[0][i]=-1*A[i]
  for i in range(1,n+1):
    for j in range(n-i):
      if i%2==1:
        if j+i==n:
          dp[i][j]=dp[i-1][j+1]+A[j]
        else:
          dp[i][j]=max(dp[i-1][j]+A[j+i],dp[i-1][j+1]+A[j])
      else:
        if j+i==n:
          dp[i][j]=dp[i-1][j+1]-A[j]
        else:
          dp[i][j]=min(dp[i-1][j]-A[j+i],dp[i-1][j+1]-A[j])
else:
  for i in range(n):
    dp[0][i]=A[i]
  for i in range(1,n+1):
    for j in range(n-i):
      if i%2==0:
        if j+i==n:
          dp[i][j]=dp[i-1][j+1]+A[j]
        else:
          dp[i][j]=max(dp[i-1][j]+A[j+i],dp[i-1][j+1]+A[j])
      else:
        if j+i==n:
          dp[i][j]=dp[i-1][j+1]-A[j]
        else:
          dp[i][j]=min(dp[i-1][j]-A[j+i],dp[i-1][j+1]-A[j])
print(dp[n-1][0])