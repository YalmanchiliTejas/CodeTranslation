n=input()
k=int(input())
l=len(n)
dp=[[[0]*(k+1) for i in range(2)] for i in range(l+1)]
#len,satu?,k
dp[0][0][0]=1#first
for i in range(1,l+1):
    x=int(n[i-1])
    for j in range(k+1):
        dp[i][1][j]+=dp[i-1][1][j]
        if j!=0:
            dp[i][1][j]+=9*dp[i-1][1][j-1]
            if x>0:
                dp[i][1][j]+=(x-1)*dp[i-1][0][j-1]
        if x!=0:
            dp[i][1][j]+=dp[i-1][0][j]
        if x==0:
            dp[i][0][j]+=dp[i-1][0][j]
        elif j>0:
            dp[i][0][j]+=dp[i-1][0][j-1]

print(dp[-1][0][-1]+dp[-1][1][-1])