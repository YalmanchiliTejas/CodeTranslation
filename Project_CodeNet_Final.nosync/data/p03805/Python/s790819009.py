ans=0
def DFS(v,visited):
    global ans
    if visited == [1]*N:
        ans += 1
        return
    for next in edge[v]:
        if visited[next] != 1:
            visited[next] = 1
            DFS(next,visited)
            visited[next] = 0 
    return

N, M = map(int,input().split())
edge = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
visited = [0 for _ in range(N)]
visited[0]=1
DFS(0,visited)
print(ans)