n,m= map(int,input().split())
a = [input().rstrip().split() for j in range(m)]
cnt = 0#現在の経路
# a
visited=[False]*n#もう訪問したか
graph = [[False for i in range(n)] for j in range(n)]#どこが連結されているか
# graph
for i in range(0,m):
    x = int(a[i][0])-1
    y = int(a[i][1])-1
    graph[x][y]=graph[y][x]=True
# graph
    
def DFS(v,n,visited):
    # print(visited)
    all_visited = True #bool
    for i in range(0,n):
        if(visited[i]==0):
            all_visited = False
    if(all_visited):
        return 1

    ret = 0

    for i in range(0,n):
        if(graph[v][i]==False):
            continue
        if(visited[i]):
            continue

        visited[i] = True
        ret += DFS(i,n,visited)
        visited[i] = False

    return ret
visited[0]=True
print(DFS(0,n,visited))