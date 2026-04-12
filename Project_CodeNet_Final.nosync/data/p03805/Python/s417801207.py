# -*- coding: utf-8 -*-

from collections import deque

N, M = map(int, input().split())
Ms = {i:set() for i in range(1, N + 1)}
for _ in range(M):
    a, b = map(int, input().split())
    Ms[a].add(b)
    Ms[b].add(a)

all = set(range(1, N + 1))
q = deque()
q.append((1, [1]))

ans = 0
while q:
    n, v = q.popleft()
    if set(v) == all:
        ans += 1
        continue
    for to in Ms[n]:
        if not to in v:
            q.append((to, v + [to]))

print(ans)
