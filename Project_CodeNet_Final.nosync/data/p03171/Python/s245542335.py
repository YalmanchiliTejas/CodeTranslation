import sys

input = sys.stdin.readline

N = int(input())
lst_a = list(map(int, input().split()))


dp = [[0 for _ in range(N+1)] for _ in range(N+1)]

for len in range(1, N + 1):
	for i in range(N+1-len):
		j = i + len
		if ((N-len) % 2 == 0):
			dp[i][j] = max(dp[i+1][j] + lst_a[i], dp[i][j-1] + lst_a[j-1])
		else :
			dp[i][j] = min(-lst_a[i] + dp[i + 1][j], -lst_a[j - 1]+dp[i][j - 1])


print(dp[0][N])