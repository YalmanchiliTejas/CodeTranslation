N, M = map(int, input().split())
Edge = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    Edge[a].append(b)
    Edge[b].append(a)

Visited = [False for i in range(N)]
Visited[0] = True
ans = 0
def DFS(i):
    allvisited = True
    for j in range(N):
        if Visited[j] == False:
            allvisited = False
    if allvisited:
        return 1
    else:
        ret = 0
        for node in Edge[i]:
            if Visited[node] == False:
                Visited[node] = True
                ret += DFS(node)
                Visited[node] = False
        return ret

print(DFS(0))
