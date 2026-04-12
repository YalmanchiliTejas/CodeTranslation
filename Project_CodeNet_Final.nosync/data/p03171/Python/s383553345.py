from sys import stdin, stdout, setrecursionlimit
from collections import deque, defaultdict
import math

rl = lambda: stdin.readline()
rll = lambda: stdin.readline().split()
rli = lambda: map(int, stdin.readline().split())

INF, NINF = float('inf'), float('-inf')

def main():
	n = int(rl())
	A = deque(rli())
	tot = sum(A)
	dp = [[A[i] if i == j else 0 for j in range(n)] for i in range(n)]
	for c in range(1, n):
		for r in range(c-1, -1, -1):
			dp[r][c] = max(A[r] - dp[r+1][c], A[c] - dp[r][c-1])
	print(dp[0][-1])
	stdout.close()

if __name__ == "__main__":
	main()