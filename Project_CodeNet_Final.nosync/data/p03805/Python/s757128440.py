n,m = map(int,input().split())
graph = [[0]*(n) for i in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    graph[a-1][b-1] = graph[b-1][a-1] = 1


visited = [True] + [False]*(n-1)
ans = 0


def dfs(x):
    global ans
    global visited
    
    if all(visited):
        ans += 1
        return
    
        
    for j in [j for j,v2 in enumerate(graph[x]) if v2 == 1 and not visited[j]]:
        visited[j] = True
        dfs(j)
        visited[j] = False

dfs(0)
print(ans)