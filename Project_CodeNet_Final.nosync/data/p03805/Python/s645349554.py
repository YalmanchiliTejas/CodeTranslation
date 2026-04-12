from collections import defaultdict
from collections import deque

N, M = map(int, input().split())

graph = defaultdict(list)
edges = []

# 無向グラフの表現
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)
    edges.append((a, b))

ans = 0
def dfs(graph, node_start, visited):
    global ans
    if sum(visited) == len(graph):
        ans += 1
        return
    for node_end in graph[node_start]:
        # 一回も訪れていない
        if not visited[node_end]:
            visited[node_end] = True
            dfs(graph, node_end, visited)
            visited[node_end] = False
    return

visited = [False] * N
visited[0] = True
dfs(graph, 0, visited)
print(ans)
