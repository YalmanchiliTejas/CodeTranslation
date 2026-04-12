n=list(input())
N=len(n)
k=int(input())
dp1=[[0 for i in range(k+1)] for j in range(N+1)]
dp2=[[0 for i in range(k+1)] for j in range(N+1)]
dp1[0][0]=1
for i in range(1,N+1):
  x=int(n[i-1])
  
  if i!=N and x!=0:
    for j in range(k+1):
      if j==0:
        dp2[i][j]=dp1[i-1][j]+dp2[i-1][j]
      else:
        dp1[i][j]=dp1[i-1][j-1]
        dp2[i][j]=dp1[i-1][j]+dp1[i-1][j-1]*(x-1)+dp2[i-1][j]+dp2[i-1][j-1]*9
  
  elif i!=N and x==0:
    for j in range(k+1):
      if j==0:
        dp1[i][j]=dp1[i-1][j]
        dp2[i][j]=dp2[i-1][j]
      else:
        dp1[i][j]=dp1[i-1][j]
        dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-1]*9
  
  elif i==N and x!=0:
    for j in range(k+1):
      if j==0:
        dp2[i][j]=dp1[i-1][j]+dp2[i-1][j]
      else:
        dp2[i][j]=dp1[i-1][j]+dp1[i-1][j-1]*x+dp2[i-1][j]+dp2[i-1][j-1]*9
  
  else:
    for j in range(k+1):
      if j==0:
        dp2[i][j]=dp2[i-1][j]
      else:
        dp2[i][j]=dp1[i-1][j]+dp2[i-1][j]+dp2[i-1][j-1]*9

print(dp2[N][k])