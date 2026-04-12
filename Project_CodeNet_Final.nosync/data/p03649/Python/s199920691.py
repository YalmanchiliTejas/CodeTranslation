import sys
stdin = sys.stdin
sys.setrecursionlimit(10**9)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

import numpy as np

n = ni()
a = np.array(na())

ans = 0

while max(a) >= n:
	for i in range(n):
		if a[i] >= n:
			b = a[i]//n
			a[i] = a[i]-b*n-b
			a+=b
			ans+=b

print(ans)