N, M = map(int, input().split())
G = [[] for i in range(N)]

for i in range(M):
  a, b = map(int, input().split())
  G[a-1].append(b-1)
  G[b-1].append(a-1)

def dfs(node, prev, visited):
    visited.append(node)
    if len(visited) == N:
        return 1
 
    res = 0
    for edge in G[node]:
        if edge == prev:
            continue
        if edge in visited:
            continue
        res += dfs(edge, prev, visited[:])
 
    return res


print(dfs(0,-1,[]))  