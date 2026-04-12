from collections import deque
from copy import deepcopy
n, m = map(int, input().split())
tree = [[] for i in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)
result = 0
visit = [-1 for _ in range(n+1)]
visit[1] = 1
q = deque([[1, deepcopy(visit)]])
while q:
    p, v = q.pop()
    if v[p] == n:
        result += 1
    for j in tree[p]:
        if v[j]<0:
            next_v = deepcopy(v)
            next_v[j] = next_v[p]+1
            q.appendleft([j, next_v])
print(result)