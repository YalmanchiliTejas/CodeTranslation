n=int(input())
K=int(input())
n_list=[]
while n>=10:
    n_list.append(n%10)
    n=(n-n%10)//10
n_list.append(n)
n_list.reverse()
x=len(n_list)
dp=[[[0]*100,[0]*100] for i in range(x+1)]
dp[0][1][0]=1
for i in range(x):
    for k in range(99):
        dp[i+1][0][k]+=dp[i][0][k]
        dp[i+1][0][k+1]+=dp[i][0][k]*9
    if n_list[i]==0:
        for k in range(99):
            dp[i+1][1][k]+=dp[i][1][k]
    else:
        n=n_list[i]
        for k in range(99):
            dp[i+1][1][k+1]+=dp[i][1][k]
            dp[i+1][0][k]+=dp[i][1][k]
            dp[i+1][0][k+1]+=dp[i][1][k]*(n-1)
ans=dp[x][0][K]+dp[x][1][K]
print(ans)
