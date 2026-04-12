n,m=map(int, input().split())
ab=[list(map(int, input().split())) for _ in range(m)]
graph=[[False for _ in range(n)] for _ in range(n)]
visited=[False for _ in range(n)]
visited[0]=True

for x in ab:
    graph[x[0]-1][x[1]-1]=True
    graph[x[1]-1][x[0]-1]=True
def dfs(v,n,visited):
    all_visited=True
    for i in range(n):
        if visited[i]==False:
            all_visited=False
    if all_visited:
        return 1
    ret=0
    for i in range(n):
        if graph[v][i]==False:
            continue
        if visited[i]:
            continue
        visited[i]=True
        ret+=dfs(i,n,visited)
        visited[i]=False
    return ret
print(dfs(0,n,visited))