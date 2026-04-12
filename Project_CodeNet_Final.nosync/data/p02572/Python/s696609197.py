from sys import stdin, stdout, setrecursionlimit
from collections import deque, defaultdict, Counter
from heapq import heappush, heappop
from functools import lru_cache
import math

#setrecursionlimit(10**6)
rl = lambda: stdin.readline()
rll = lambda: stdin.readline().split()
rli = lambda: map(int, stdin.readline().split())
rlf = lambda: map(float, stdin.readline().split())

INF, NINF = float('inf'), float('-inf')
MOD = 10**9 + 7

def main():
	n = int(rl())
	A = list(rli())
	psums = [A[0]]
	ans = 0
	for i in range(1, n):
		psums.append(psums[-1] + A[i])
	for j in range(1, n):
		ans += psums[j-1] * A[j]
		ans %= MOD 
	print(ans)
	stdout.close()

if __name__ == "__main__":
	main()