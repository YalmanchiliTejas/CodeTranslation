n, m = map(int, input().split())
to = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    to[a-1].append(b-1)
    to[b-1].append(a-1)
    

def dfs(v, n, visited):
    #print(visited)
    all_visited = True
    for i in visited:
        if not i:
            all_visited = False
            break
    if all_visited:
        return(1)
    
    ret = 0
    for i in range(1, n):
        #print(ret)
        if to[i].count(v) == 0:
            continue
        if visited[i]:
            continue
        visited[i] = True
        ret += dfs(i, n, visited)
        visited[i] = False
    return(ret)

visited = [False for _ in range(n)]
visited[0] = True
print(dfs(0, n ,visited))