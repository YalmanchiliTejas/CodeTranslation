N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

visited = [False]*N

ans = 0
import copy

def dfs(node, visited):
    global ans
    v = copy.copy(visited)
    if v[node]:
        return
    v[node] = True
    if all(v):
        ans += 1
    else:
        cands = graph[node]
        for cand in cands:
            dfs(cand, v)

dfs(0, visited)
print(ans)
