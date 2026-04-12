N=input()
K=int(input())

dig=len(str(N))

dp=[[[0,0,0,0] for _ in range(2)] for i in range(dig+1)]
#dp[i][j][k]は上からi桁目まで，tightかどうか，0ではない数の個数(0,1,2,3)

n=int(N[0])
dp[1][0][0]=1
dp[1][0][1]=n-1
dp[1][1][1]=1


for i in range(1,dig):
    for j in range(2):
        if j==0:
            dp[i+1][j][0]=dp[i][j][0]
            dp[i+1][j][1]+=dp[i][j][0]*9+dp[i][j][1]
            dp[i+1][j][2]+=dp[i][j][1]*9+dp[i][j][2]
            dp[i+1][j][3]+=dp[i][j][2]*9+dp[i][j][3]
        if j==1:
            if N[i]=="0":
                for k in range(4):
                    dp[i+1][j][k]=dp[i][j][k]
            else:
                #tight to tight
                dp[i+1][j][1]=dp[i][j][0]
                dp[i+1][j][2]=dp[i][j][1]
                dp[i+1][j][3]=dp[i][j][2]
                
                #tight to not tight
                n=int(N[i])
                dp[i+1][j-1][1]+=dp[i][j][0]*(n-1) + dp[i][j][1]
                dp[i+1][j-1][2]+=dp[i][j][1]*(n-1) + dp[i][j][2]
                dp[i+1][j-1][3]+=dp[i][j][2]*(n-1) + dp[i][j][3]
                
            
ans=dp[-1][0][K]+dp[-1][1][K]
print(ans)

