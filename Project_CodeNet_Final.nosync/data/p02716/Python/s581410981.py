N=int(input())
alist=list(map(int,input().split()))

if N%2==0:
  dp=[]
  for i in range(2):
    array=[0]*N
    dp.append(array)
    
  #init
  dp[0][0]=alist[0]
  dp[1][1]=alist[1]
  for i in range(2,N):
    dp[0][i]=dp[0][i-2]+alist[i]
    dp[1][i]=max(dp[1][i-2]+alist[i],dp[0][i-3]+alist[i])
    
  print(max(dp[0][-2],dp[1][-1]))
else:
  dp=[]
  for i in range(3):
    array=[0]*N
    dp.append(array)

  #init
  dp[0][0]=alist[0]
  dp[0][2]=alist[0]+alist[2]
  dp[1][1]=alist[1]
  dp[2][2]=alist[2]
  for i in range(3,N):
    dp[0][i]=dp[0][i-2]+alist[i]
    dp[1][i]=max(dp[1][i-2]+alist[i],dp[0][i-3]+alist[i])
    dp[2][i]=max(dp[2][i-2]+alist[i],dp[1][i-3]+alist[i],dp[0][i-4]+alist[i])

  #dp[0][-1] is NG
  print(max(dp[0][-3],dp[1][-2],dp[2][-1]))