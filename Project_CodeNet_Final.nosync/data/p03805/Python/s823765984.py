def dfs(visited, s):
    visited = visited[:]
    global ans
    visited[s] = True
    for t in graph[s]:
        if not visited[t]:
            dfs(visited, t)
    if all(visited):
        ans += 1


N, M = map(int, input().split())  # N頂点, M辺存在する

graph = [[] for _ in range(N)]
visited = [False] * N

for _ in range(M):  # M辺を受け取る
    a, b = map(lambda x: int(x)-1, input().split())
    graph[a].append(b)
    graph[b].append(a)


ans = 0
dfs(visited, 0)

print(ans)
