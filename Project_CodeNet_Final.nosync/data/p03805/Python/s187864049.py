def one_stroke_path(path, graph, i):
    if len(path) == N:
        return 1
    if not graph[i]:
        return 0
    if graph[i] in path:
        return 0
    res = 0
    for node in graph[i]:
        if not node in path:
            res += one_stroke_path(path + [node], graph, node)
    return res

N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

ans = 0
path = [0]
i = 0

print(one_stroke_path(path, graph, i))
