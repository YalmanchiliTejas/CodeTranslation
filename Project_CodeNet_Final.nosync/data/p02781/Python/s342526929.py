import sys
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 10**9 + 7

N = ri()
K = ri()

nums = list(map(int, list(str(N))))
L = len(nums)
dp = [ [[0]*2 for _ in range(K+2)] for _ in range(L+1)]

dp[0][0][0] = 1

for i in range(L):
	for j in range(K+1):
		for k in range(2):
			for d in range(10):
				ni, nj, nk = i+1, j, k
				if d > 0:
					nj += 1
				if nj > K: continue
				if k == 0:
					if d < nums[i]:
						nk = 1
					elif d > nums[i]:
						continue
				dp[ni][nj][nk] += dp[i][j][k]
print(sum(dp[L][K]))
