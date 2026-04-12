N,M = map(int,input().split())

graph  = [[] for _ in range(N+1)]
for _ in range(M):
    x,y = map(int,input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = [0]*(N)
ans = 0

def DFS(pos):
    global visited
    global ans
    if sum(visited) == N:
        ans += 1
        return

    for i in graph[pos]:
        if visited[i-1]:
            continue
        visited[i-1] = 1
        DFS(i)
        visited[i-1] = 0
    return

visited[0] = 1
DFS(1)
print(ans)