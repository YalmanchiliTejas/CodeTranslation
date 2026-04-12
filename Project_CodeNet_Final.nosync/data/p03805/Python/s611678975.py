def dfs(v, N, visited, ret, route):
    if sum(visited) == N:
        return ret + 1
    
    visitable = []
    for pair in route:
        if v in pair:
            if visited[pair[0]] == 0:
                visitable.append(pair[0])
            elif visited[pair[1]] == 0:
                visitable.append(pair[1])
    
    for v in visitable:
        visited[v] = 1
        ret = dfs(v, N, visited, ret, route)
        visited[v] = 0
    
    return ret

N, M = map(int, input().split())
route = []
for i in range(M):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    route.append([a, b])
visited = [0] * N
visited[0] = 1
ret = dfs(0, N, visited, 0, route)
print(ret)