n,m = map(int,input().split())
graph = [[False for i in range(n)] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    graph[a-1][b-1],graph[b-1][a-1] = True,True

def dfs(num,visited):
    if visited==[True]*n:
        return 1
    res = 0
    for i in range(n):
        if graph[num][i] and not visited[i]:
            visited[i] = True
            res += dfs(i,visited)
            visited[i] = False
    return res

visit = [True] + [False] * (n-1)
print(dfs(0,visit))
