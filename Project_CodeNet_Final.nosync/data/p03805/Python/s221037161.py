#!/usr/bin/env python3
# input
from collections import deque
import itertools

n, m = map(int, input().split())
path = [[] for _ in range(n)]
for i in range(m):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    path[a].append(b)
    path[b].append(a)
# n-1 ! を全探索する
all_lis = itertools.permutations(range(1, n))  # 1(0)は出発点なので除く
# print(all_lis)

ans = 0
for i in all_lis:
    start = 0# これをfor の外においていて爆死。
    ok = 1
    for j in range(n - 1):
        if i[j] not in path[start]:
            ok = 0
            break
        else:
            start = i[j]
    if ok:
        ans += 1
print(ans)
