ans = 0
def dfs(v, visitedNode, graph):
    visitedNode[v] = 1
    # print(visitedNode)
    if all(visitedNode):
        global ans
        ans += 1
        return
    for node in graph[v]:
        if visitedNode[node]:
            # 探索済みならば、ほかの隣接候補へ。
            continue
        else:
            # 未探索ならば、次の階層を調べる。
            dfs(node, visitedNode[:], graph)


N, M = map(int, input().split())
v = 0
visitedNode = [0] * N


graph = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)
# print(graph)


dfs(v, visitedNode, graph)
print(ans)
