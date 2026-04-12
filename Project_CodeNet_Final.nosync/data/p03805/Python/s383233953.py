ans = 0
def dfs(v, visitedNode, graph):
    visitedNode[v] = 1
    if all(visitedNode):
        global ans
        ans += 1
        return
    for node in graph[v]:
        if visitedNode[node]:
            continue
        else:
            dfs(node, visitedNode[:], graph)


N, M = map(int, input().split())
v = 0
visitedNode = [0] * N


# 隣接リストを作成する
graph = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)


# 深さ優先探索で経路数を数える
dfs(v, visitedNode, graph)
print(ans)
