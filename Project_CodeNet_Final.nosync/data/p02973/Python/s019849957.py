
import sys
from collections import deque, defaultdict
import copy
import bisect
input=sys.stdin.readline
sys.setrecursionlimit(10 ** 9)

N = int(input())
A = []
for i in range(N):
	A.append(int(input()))

B = []
min = -10000000000
for i in range(N):
	loc = bisect.bisect_right(B, -A[i])
	if loc == len(B):
		B.append(-A[i])
	else:
		B[loc] = -A[i]

print(len(B))