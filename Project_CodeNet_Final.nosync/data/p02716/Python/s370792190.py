n,*a=map(int,open(0).read().split())
dp=[[0]*n for _ in range(3)]
for i in range(n):
	if i%2:
		dp[1][i]=max(dp[2][i-3]+a[i],dp[1][i-2]+a[i])
	elif i>1:
		dp[0][i]=max(dp[0][i-2]+a[i],dp[1][i-3]+a[i],dp[2][i-4]+a[i])
		dp[2][i]=dp[2][i-2]+a[i]
	else:
		dp[2][i]=dp[2][i-2]+a[i]
print(max(dp[2][-3],dp[1][-2],dp[0][-1]) if n%2 else max(dp[1][-1],dp[2][-2]))