def findpath(graph, root, rest):
    if len(rest) == 0:
        return 1
    res = 0
    for n in graph[root]:
        if n in rest:
            rest.remove(n)
            res += findpath(graph, n, rest)
            rest.add(n)
    return res

n, m = map(int, input().split())
graph = {}
for _ in range(m):
    a, b = map(int, input().split())
    if a not in graph:
        graph[a] = set()
    graph[a].add(b)
    if b not in graph:
        graph[b] = set()
    graph[b].add(a)

print(findpath(graph, 1, set(range(2, n + 1))))
