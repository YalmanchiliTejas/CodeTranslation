from collections import deque
from itertools import permutations as perm

N,M = map(int, input().split())
A = {}
for i in range(M):
    a,b = map(int, input().split())
    if a not in A:
        A[a] = {}
    if b not in A:
        A[b] = {}
    A[a][b] = A[b][a] = 1

ans = 0
for lst in perm([i for i in range(2,N+1)]):
    tmp = 1
    for i in range(N-1):
        if lst[i] not in A[tmp]:
            break
        tmp = lst[i]
    else:
        ans += 1
print(ans)