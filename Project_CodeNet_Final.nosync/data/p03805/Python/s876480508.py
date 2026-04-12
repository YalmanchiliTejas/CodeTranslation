N,M = map(int,input().split())
intx = lambda x:int(x)-1
#mp = [list(map(intx,input().split())) for _ in range(M)]
adj = [[0]*N for _ in range(N)]
for i in range(M):
    a,b = map(intx,input().split())
    adj[a][b] = 1
    adj[b][a] = 1
#print(adj)

visited = [False]*N
def dfs(loc,depth):
    if visited[loc]:
        return 0
    if depth == N-1:
        return 1
        
    visited[loc] = True
    path = 0
    for i in range(N):
        if adj[loc][i]:
            path+=dfs(i,depth+1)
    
    visited[loc] = False
    
    return path
    
print(dfs(0,0))