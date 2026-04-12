from collections import deque, defaultdict

N, M = map(int, input().split())
nodes = defaultdict(set)
for _ in range(M):
    u, v = map(int, input().split())
    nodes[u].add(v)
    nodes[v].add(u)

visited = [False]*N

def dfs(x, visited, st):
    res = 0
    v = visited.copy()
    v[x-1] = True
    if st == N:
        return 1

    for node in nodes[x]:
        if not v[node-1]:
            res += dfs(node, v, st+1)
    return res

print(dfs(1, visited, 1))
