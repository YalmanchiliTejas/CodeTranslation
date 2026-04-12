N, M = map(int, input().split())
from collections import defaultdict

counter = 0

g = defaultdict(list)
for i in range(M):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

visited = []
def h(a):
    global counter
    visited.append(a)
    if len(visited) == N:
        counter += 1
        return
    for i in g[a]:
        if not i in visited:
            h(i)
            visited.remove(i)
h(1)
print(counter)