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

	dp = [[[0]*2 for j in range(d)] for i in range(len(x)+1)]
	dp[0][0][1] = 1
	for i in range(len(x)):
		for digsum in range(d):
			for tight in range(2):
				for dig in range(x[i]+1 if tight else 10):
					ns = (digsum + dig) % d 
					ntight = 1 if tight and dig == x[i] else 0
					dp[i+1][ns][ntight] += dp[i][digsum][tight]
					dp[i+1][ns][ntight] %= MOD

	ans = (dp[len(x)][0][0] + dp[len(x)][0][1] - 1) % MOD
	print(ans)
	stdout.close()

if __name__ == "__main__":
	main()