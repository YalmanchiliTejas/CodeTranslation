n=input()
k=int(input())
m=len(n)

dp=[[[0]*2 for _ in range(4)] for _ in range(m+1)]

dp[0][0][0]=1
keta=int(n[0])
dp[1]=[[0,1],[1,keta-1],[0,0],[0,0]]
  
for i in range(1,m):
  keta=int(n[i])
  dp[i+1][0][0]+=dp[i][0][0]*(keta==0)
  dp[i+1][0][1]+=(dp[i][0][0]*(keta>0)+dp[i][0][1])
  for j in range(3):
    dp[i+1][j+1][0]+=dp[i][j][0]*(keta!=0)+dp[i][j+1][0]*(keta==0)
    dp[i+1][j+1][1]+=(dp[i][j][0]*max(keta-1,0)+dp[i][j][1]*9
                      +dp[i][j+1][0]*(keta>0)+dp[i][j+1][1])
    
                    
print(dp[m][k][0]+dp[m][k][1])
      