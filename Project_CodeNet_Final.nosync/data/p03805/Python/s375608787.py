nmax = 8
def dfs(v, N, visited):
    all_visited=True
    for i in range(N):
        if visited[i]==False:
            all_visited=False

    if all_visited==True:
        return 1

    ret=0
    for i in range(N):
        if graph[v][i]==False:
            continue
        if visited[i]==True:
            continue

        visited[i]=True
        ret+=dfs(i,N,visited)
        visited[i]=False

    return ret

N, M = map(int, input().split())
graph = [[False]*N for i in range(N)]
for i in range(M):
    A, B = map(int, input().split())
    graph[A-1][B-1]=True
    graph[B-1][A-1]=True

visited = [False]*N

visited[0]=True
print(dfs(0,N,visited))





