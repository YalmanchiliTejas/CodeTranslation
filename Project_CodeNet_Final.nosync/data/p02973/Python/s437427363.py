from bisect import bisect_left
from collections import deque
N = int(input())
A = [int(input()) for _ in range(N)]
G = deque([])
for i in range(N):
    a = A[i]
    ind = bisect_left(G,a)
    if ind==0:
        G.appendleft(a)
    else:
        G[ind-1] = a
print(len(G))