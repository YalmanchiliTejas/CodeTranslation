import sys
input = sys.stdin.readline
'''
allinputs = iter(input().splitlines())
input = lambda : next(allinputs)
#'''
N = int(input())
a = list(map(int, input().split()))
dp = [[0] * N for _ in range(N)]
#dp[n][i]...n+1:残った要素の個数、i:左端の要素が初期状態のi番目の要素、dp:X-Y

for n in range(N):
	for i in range(N - n):
		if n == 0:
			dp[n][i] = a[i]
		else:
			dp[n][i] = max(a[i] - dp[n - 1][i + 1], a[i + n] - dp[n - 1][i])
			
print(dp[N - 1][0])
