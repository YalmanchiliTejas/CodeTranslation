from bisect import bisect
n = int(input())
a = [int(input()) for _ in range(n)]
dp = [1 for _ in range(n+2)]
for i in range(n):
	b = bisect(dp, -a[i])
	dp[b] = -a[i]
ans = 1
while dp[ans] <= 0:
	ans += 1
print(ans)