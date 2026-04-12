from collections import deque
from copy import deepcopy

N, M = map(int, input().split())
paths = [[] for n in range(N)]
def add_paths(a, b):
    paths[a - 1].append(b - 1)
    paths[b - 1].append(a - 1)

for i in range(M):
    a, b = map(int, input().split())
    add_paths(a, b)
route = deque([(0, paths[0], [False for n in range(N)])])
ans = 0
while len(route) > 0:
    vertex, path, visited = route.pop()
    visited[vertex] = True
    for i in path:
        if visited[i] != True:
            route.append((i, paths[i], deepcopy(visited)))
    if visited.count(False) == 0:
        ans += 1
print(ans)