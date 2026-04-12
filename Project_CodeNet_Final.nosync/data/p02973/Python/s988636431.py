import bisect
import sys
import collections
input = sys.stdin.readline
N = int(input())
A = [int(input()) for i in range(N)]
B = [A[0]]
B = collections.deque(B)
tmp = [0]*N
ans = 1
for i in range(1, N):
    id = bisect.bisect_left(B, A[i])
    if id == 0:
        B.appendleft(A[i])
    else:
        B[id-1] = A[i]
print(len(B))
