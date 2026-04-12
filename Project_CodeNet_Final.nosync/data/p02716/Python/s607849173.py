import sys
n = int(input())
a = list(map(int, input().split()))
if n%2 == 0:
	dp = [[-10**20 for _ in range(2)] for _ in range(n)]
	dp[0][0] = a[0]
	dp[0][1] = 0
	dp[1][1] = a[1]
	for i in range(1, n):
		if i%2 == 0:
			dp[i][0] = dp[i-2][0] + a[i]
			dp[i][1] = max(dp[i-1][0], dp[i-1][1])
		else:
			dp[i][0] = dp[i-1][0]
			if i > 1:
				dp[i][1] = max(dp[i-2][1] + a[i], dp[i-3][0] + a[i])

else:
	dp = [[-10**20 for _ in range(3)] for _ in range(n)]
	dp[0][0] = a[0]
	dp[0][1] = 0
	dp[1][1] = a[1]
	dp[0][2] = 0
	dp[1][2] = 0
	dp[2][2] = a[2]

	for i in range(1, n):
		if i%2 == 0:
			if i < n-1:
				dp[i][0] = dp[i-2][0] + a[i]
			else:
				dp[i][0] = dp[i-1][0]
			dp[i][1] = max(dp[i-1][1], dp[i-2][0])
			if i > 2:
				dp[i][2] = max(dp[i-2][2] + a[i], dp[i-4][0] + a[i], dp[i-3][1] + a[i])
		else:
			dp[i][0] = dp[i-1][0]
			if i > 1:
				dp[i][1] = max(dp[i-2][0] + a[i], dp[i-2][1] + a[i])
				dp[i][2] = max(dp[i-1][2], dp[i-2][1], dp[i-3][0])

print(max(dp[n-1]))