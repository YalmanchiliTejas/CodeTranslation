N=input()
k=int(input())
ln=len(N)
DP=[[[0]*2 for _ in range(k+1)] for _ in range(len(N)+1)]
DP[0][0][0]=1
for i in range(1,len(N)+1):
  DP[i][0][1]=1
for i in range(len(N)):
  ni=int(N[i])
  for j in range(1,k+1):
    DP[i+1][j][1]=DP[i][j][1]+max(0,ni-1)*DP[i][j-1][0]+9*DP[i][j-1][1]
    if ni==0:
      DP[i+1][j][0]=DP[i][j][0]
    else:
      DP[i+1][j][0]=DP[i][j-1][0]
      DP[i+1][j][1]+=DP[i][j][0]
print(DP[ln][k][0]+DP[ln][k][1])
