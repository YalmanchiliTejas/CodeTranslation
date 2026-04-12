from sys import stdin, stdout
from collections import deque, defaultdict
from functools import lru_cache

rl = lambda: stdin.readline()
rll = lambda: stdin.readline().split()
rli = lambda: map(int, stdin.readline().split())

INF, NINF = float('inf'), float('-inf')

def main():
	MOD = 10**9 + 7
	x = []
	for c in rll()[0]:
		x.append(int(c))
	d = int(rl())
	ans = 0

	dp = [[0 for __ in range(2)] for _ in range(d)]
	dp[0][1] = 1
	for i in range(len(x)):
		ndp = [[0 for __ in range(2)] for _ in range(d)]
		for digsum in range(d):
			for tight in range(2):
				for nd in range(x[i]+1 if tight else 10):
					ns = (digsum + nd) % d 
					ntight = 1 if tight and nd == x[i] else 0
					ndp[ns][ntight] += dp[digsum][tight]
					ndp[ns][ntight] %= MOD
		dp = ndp

	ans = (dp[0][0] + dp[0][1] - 1) % MOD
	print(ans)
	stdout.close()

if __name__ == "__main__":
	main()