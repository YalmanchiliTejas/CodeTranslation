n=int(input())
K=int(input())
m=len(str(n))
N=list(map(int,str(n)))
dp=[[[0,0]for j in range(K+1)]for i in range(m+1)]
dp[0][0][0]=1
for i in range(1,1+m):
    for j in range(K+1):
        for k in range(10):
            if k==0:
                if N[i-1]==k:
                    dp[i][j][0]+=dp[i-1][j][0]
                elif N[i-1]>k:
                    dp[i][j][1]+=dp[i-1][j][0]
                dp[i][j][1]+=dp[i-1][j][1]
            else:
                if j<K:
                    if N[i-1]==k:
                        dp[i][j+1][0]+=dp[i-1][j][0]
                    elif N[i-1]>k:
                        dp[i][j+1][1]+=dp[i-1][j][0]
                    dp[i][j+1][1]+=dp[i-1][j][1]

print(sum(dp[-1][K]))