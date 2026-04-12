N=int(input())
K=int(input())

sN=str(N)
keta=len(sN)

#dp[i][j][t]=Nと同じ桁数の整数で上からi桁目までで0でない数字がj個あるものの個数
dp=[[[0]*2 for __ in range(K+1)] for _ in range(keta+1)]
dp[0][0][1]=1

for i in range(1,keta+1):
    for j in range(K+1):
        if sN[i-1]=='0':
            dp[i][j][1] = dp[i-1][j][1]
        elif j>0:
            dp[i][j][1] = dp[i-1][j-1][1]
        dp[i][j][0] = dp[i-1][j][0]
        if sN[i-1]!='0':
            dp[i][j][0] += dp[i-1][j][1]
        if j>0:
            dp[i][j][0] += dp[i-1][j-1][1]*(max(0,int(sN[i-1])-1))
            dp[i][j][0] += dp[i-1][j-1][0]*9

print(dp[keta][K][0]+dp[keta][K][1])
