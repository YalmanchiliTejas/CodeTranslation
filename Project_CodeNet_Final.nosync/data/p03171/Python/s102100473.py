n = int(input())
a = list(map(int, input().split( )))

dp = [[0]*n for i in range(n)]

for i in range(n):#奇数偶数で最終手番は変わる
    dp[i][i] = a[i]

for d in range(1,n):
    for j in range(n-d):
        if d%2 == 1:#最後打たない方
            dp[j][j+d] = min(dp[j][j+d-1]-a[j+d],dp[j+1][j+d]-a[j])
        else:#最後打つ方
            dp[j][j+d] = max(dp[j][j+d-1]+a[j+d],dp[j+1][j+d]+a[j])
if n%2==1:
	 print(dp[0][n-1])
else:
  	print(-dp[0][n-1])