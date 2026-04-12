n, m = map(int, input().split())
g = [[] for i in range(n)]
for i in range(m):
    u,v = map(int, input().split())
    g[u-1].append(v-1)
    g[v-1].append(u-1)

visited = [0] * n

def dfs(now, pre):
    if sum(visited) == n:
        return 1
    
    res = 0
    
    for i in g[now]:
        if i != pre and visited[i] == 0:
            visited[i] = 1
            res = res + dfs(i, now)
            visited[i] = 0
    
    return res

visited[0] = 1
print(dfs(0, -1))