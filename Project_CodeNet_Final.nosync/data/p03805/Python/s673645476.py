N,M = map(int,input().split())
edges = [list() for _ in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)
visited = [0]*N
cnt = 0
def dfs(u,visited):
    visited = visited[:]
    global cnt
    visited[u] = True
    if all(visited):
        cnt += 1
        return
    for v in edges[u]:
        if not visited[v]:
            dfs(v,visited)
    return 0

dfs(0,visited)
print(cnt)