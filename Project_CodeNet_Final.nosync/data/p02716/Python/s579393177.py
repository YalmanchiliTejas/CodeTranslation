n=int(input())
A=list(map(int,input().split()))
m=-10**15
#dp[i][j]=i番目までで、j回選ばない連続を使ったときの最大値
dp1=[[m,m,m] for i in range(n)] #最後を使うとき
dp0=[[m,m,m] for i in range(n)] #最後を使わないとき
dp1[0][0]=A[0]
dp0[0][1]=0 #最初選ばないときはj=1にする
for i in range(1,n):
    for j in range(3):
        dp1[i][j]=max(dp1[i][j],dp0[i-1][j]+A[i])
        dp0[i][j]=max(dp0[i][j],dp1[i-1][j])
        if j!=2:
            dp0[i][j+1]=max(dp0[i][j+1],dp0[i-1][j])
if n%2==0:
    print(max(dp1[n-1][1],dp0[n-1][0]))
else:
    print(max(dp1[n-1][2],dp0[n-1][1]))