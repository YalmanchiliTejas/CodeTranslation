N, M = map(int, input().split())
edge = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

from collections import deque

d = deque([[0]]) #(頂点、長さ)
from copy import copy
ans = 0
while len(d):
    vs = d.popleft()
    for w in edge[vs[-1]]:
        if w not in vs:
            vs_copy = copy(vs)
            vs_copy.append(w)
            if len(vs_copy)==N:
                ans += 1
            else:
                d.append(vs_copy)
print(ans)