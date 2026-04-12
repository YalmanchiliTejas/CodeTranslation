n = int(input())
l = list(map(int, input().split()))
tl = sum(l)
dp=[]
for _ in range(n):
    dp.append([0]*n)
for i in range(n):
    dp[i][i]=l[i]
for i in range(n-1):
    dp[i][i+1]=max(l[i],l[i+1])
for i in range(n-1,-1,-1):
    for j in range(i+2,n):
        ans1=l[i]+min(dp[i+2][j],dp[i+1][j-1])
        ans2=l[j]+min(dp[i+1][j-1],dp[i][j-2])
        dp[i][j]=max(ans1,ans2)
a = dp[0][n-1]
b = tl-a
print(a-b)