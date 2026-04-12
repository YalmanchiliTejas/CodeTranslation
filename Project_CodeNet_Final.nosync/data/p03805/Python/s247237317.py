def DFS(now, visited):

    if len(visited) == n:
        ans.append(1)
        return

    for i in graph[now]:
        if not i in visited:
            DFS(i, visited + [i])


n, m = map(int, input().split())
graph = [[] for i in range(n)]
ans = []

for i in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

DFS(0,[0])

print(len(ans))
