N, M = list(map(int, input().split()))
AB = []
for i in range(M):
    a, b = list(map(int, input().split()))
    AB.append([a, b])

graph = []
for i in range(N):
    graph.append([False]*N)

for a, b in AB:
    a -= 1
    b -= 1
    graph[a][b] = True
    graph[b][a] = True

VISITED = [None] * N

count = 0

def dfs(v):
    global count
    if all(VISITED):
        count += 1
        return

    edges = graph[v]
    for i, ei in enumerate(edges):
        if ei and not VISITED[i]:
            VISITED[i] = True
            dfs(i)
            VISITED[i] = False

VISITED[0] = True
dfs(0)
print(count)