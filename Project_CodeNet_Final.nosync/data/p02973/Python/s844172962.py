import bisect
from collections import deque
N = int(input())
A = [int(input()) for n in range(N)]

tree = deque([[A[0]]])
leaf = deque([A[0]])
for n in range(1,N):
    a = A[n]
    pos = min(n-1,bisect.bisect_left(leaf,a)-1)
    if pos==-1:
        tree.appendleft([a])
        leaf.appendleft(a)
    else:
        tree[pos].append(a)
        leaf[pos] = a
print(len(tree))