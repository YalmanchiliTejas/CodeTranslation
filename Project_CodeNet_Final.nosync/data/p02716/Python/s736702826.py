n=int(input())
a= list(map(int, input().split()))

if n==2:
    print(max(a[0],a[1]))
    exit()
    
dp=[[-float('inf'),-float('inf'),-float('inf')] for i in range(n)]
# dp[i][0]:iまででまだ飛ばしてない
# dp[i][1]:一つ飛ばしてる
# dp[i][2]:２つ飛ばしてる
dp[0][0]=a[0]
dp[1][1]=a[1]
dp[2][2]=a[2]

for i in range(2,n):
    dp[i][0]=dp[i-2][0]+a[i]
    if i>=3:
        dp[i][1]=max(dp[i-2][1]+a[i],dp[i-3][0]+a[i])
    if i>=4:
        dp[i][2]=max(dp[i-2][2]+a[i],dp[i-3][1]+a[i],dp[i-4][0]+a[i])

if n%2==0:
    print(max(dp[-2][0],dp[-1][1]))
else:
    print(max(dp[-3][0],dp[-2][1],dp[-1][2]))