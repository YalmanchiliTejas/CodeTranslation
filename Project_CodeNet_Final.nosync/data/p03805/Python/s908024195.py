N, M = list(map(int, input().split(" ")))

graph = [list() for i in range(N+1)]

for i in range(M):
    a, b = list(map(int, input().split(" ")))
    graph[a].append(b)
    graph[b].append(a)
    
def DFS(node, prev, visited):
    visited.append(node)
    if len(visited) == N:
        return 1
    
    res = 0
    for edge in graph[node]:
        if edge == prev:
            continue
        elif edge in visited:
            continue
        res += DFS(edge, prev, visited[:])
        
    return res

print(DFS(1, 0, []))