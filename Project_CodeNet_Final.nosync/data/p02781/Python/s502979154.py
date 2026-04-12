N_str=input()
K=int(input())

#print(N_str)
digit_N=len(N_str)

#dp[i][j][k]
#i:eqflag, j:digit, k:K
#dp=[[[0]*2 for _ in range(digit_N)] for _ in range(K+1)]
dp=[[[0]*(K+1) for _ in range(digit_N)] for _ in range(2)]
dp[0][0][0]=1
dp[0][0][1]=int(N_str[0])-1
dp[1][0][1]=1
#print(dp)

for j in range(1,digit_N):
  digit=int(N_str[j])
  for k in range(K+1):
    if digit==0:
      if k==0:
        dp[0][j][0]=dp[0][j-1][0]
      else:
        dp[0][j][k]=dp[0][j-1][k]+9*dp[0][j-1][k-1]
        dp[1][j][k]=dp[1][j-1][k]
    else:
      if k==0:
        dp[0][j][0]=dp[0][j-1][0]
      else:
        dp[0][j][k]=dp[0][j-1][k]+9*dp[0][j-1][k-1]+dp[1][j-1][k]+(digit-1)*dp[1][j-1][k-1]
        dp[1][j][k]=dp[1][j-1][k-1]
    
#print(dp)
print(dp[0][-1][K]+dp[1][-1][K])