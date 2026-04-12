import sys
import bisect
input = sys.stdin.readline
inpl = lambda: list(map(int,input().split()))
N = int(input())
A = [0]*N
for i in range(N):
    A[i] = int(input())
C = []
for a in A:
    k = bisect.bisect_right(C,-a)
    if k >= len(C):
        C.append(-a)
    else:
        C[k] = -a
print(len(C))