import sys
def input():
	return sys.stdin.readline()[:-1]
n, s = map(int, input().split())
a = list(map(int, input().split()))
MOD = 998244353
dp = [0 for _ in range(3001)]
dp[0] = 1
ans = 0
for i in range(n):
	for j in range(s, a[i]-1, -1):
		dp[j] += dp[j-a[i]]
		dp[j] %= MOD
	dp[a[i]] += i
	dp[a[i]] %= MOD
	ans += dp[s]
	ans %= MOD
print(ans)