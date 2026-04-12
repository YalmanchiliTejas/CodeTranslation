from sys import stdin, stdout, setrecursionlimit
from collections import deque, defaultdict, Counter
from heapq import heappush, heappop
from functools import lru_cache
import math

setrecursionlimit(10**6)
rl = lambda: stdin.readline()
rll = lambda: stdin.readline().split()
rli = lambda: map(int, stdin.readline().split())
rlf = lambda: map(float, stdin.readline().split())

INF, NINF = float('inf'), float('-inf')
MOD = 10**9 + 7

def main():
	K = rll()[0]
	D = int(rl())
	lim = []
	for c in K: lim.append(int(c))
	n = len(lim)
	dp = [[[0]*D for j in range(2)] for i in range(n+1)]
	dp[0][1][0] = 1
	for i in range(n):
		for tight in range(2):
			for ds in range(D):
				md = lim[i] if tight else 9
				for d in range(md+1):
					nt = 1 if tight and lim[i] == d else 0
					nds = (d + ds) % D
					dp[i+1][nt][nds] += dp[i][tight][ds]
					dp[i+1][nt][nds] %= MOD
	ans = (dp[n][0][0] + dp[n][1][0] - 1) % MOD
	print(ans)
	stdout.close()

if __name__ == "__main__":
	main()