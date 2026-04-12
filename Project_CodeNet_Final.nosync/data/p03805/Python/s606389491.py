import itertools as it

N, M = map(int, input().split())
graph = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    graph[a].append(b)
    graph[b].append(a)
ans = 0
for path in it.permutations(range(N)):
    if path[0] != 0:
        continue
    is_connected = True
    for ith_edge in range(len(path) - 1):
        if path[ith_edge + 1] not in graph[path[ith_edge]]:
            is_connected = False
            break
    if is_connected:
        ans += 1
print(ans)
