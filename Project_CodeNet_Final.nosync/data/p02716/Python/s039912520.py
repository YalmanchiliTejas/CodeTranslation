n = int(input())
a = list(map(int, input().split()))
iseven=(n%2==0)

if n==2:
    print(max(a))
    exit()
dp = [[-float("inf") for _ in range(3)] for _ in range(n)]
dp[0][0]=a[0]
dp[1][1]=a[1]
if n>2:
    dp[2][2]=a[2]

for i in range(n):
    for k in range(3):
        if i+2<n:
            dp[i+2][k] = max(dp[i+2][k], dp[i][k] + a[i+2])
        if k<=1 and i+3<n:
            dp[i+3][k+1] = max(dp[i+3][k+1], dp[i][k] + a[i+3])
        if not iseven and k==0 and i+4<n:
            dp[i+4][k+2] = max(dp[i+4][k+2], dp[i][k] + a[i+4])


if iseven:
    ans=max([dp[-1][0],dp[-1][1]])
else:
    ans=max([dp[-3][0],dp[-2][1],dp[-1][2]])
print(ans)