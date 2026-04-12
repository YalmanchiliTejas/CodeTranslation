n="0"+input()
x=len(n)
k=int(input())
l=[int(i) for i in n]
dp=[[[0]*5,[0]*5] for i in range(x)]
dp[0][0][0]=1
r=0
#dp 0=n, 1=under
for i in range(1,x):
    for j in range(2):
        dp[i][1][0]=1
        for p in range(1,k+1):
            if j==0 and l[i]==0:
                dp[i][0][p]=dp[i-1][0][p]
            elif j==0 and l[i]!=0 and dp[i-1][0][p-1]:
                dp[i][0][p]=1
            if j==1:
                dp[i][1][p]=dp[i-1][1][p]+(dp[i-1][1][p-1]*9)+(dp[i][0][p]*max(0,l[i]-1))+([0,1][l[i]!=0 and dp[i-1][0][p]])
print(dp[-1][0][k]+dp[-1][1][k])