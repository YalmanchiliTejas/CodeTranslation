n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)
def DFS(node, seen):
    if len(seen)==n-1:
        return 1
    tmp = 0
    for i in graph[node]:
        if i in seen:
            continue
        tmp += DFS(i, seen|{node})
    return tmp
print(DFS(0, set()))