N, M = list(map(int,input().split()))
G = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    G[a - 1].append(b - 1)
    G[b - 1].append(a - 1)

def dfs(depth, node):
    global visited
    global ans
    visited[node] = 1
    if depth == N - 1:
        if sum(visited) == N:  ans += 1
        return
    for i in G[node]:
        if visited[i] == 0:
            dfs(depth + 1, i)
            visited[i] = 0
            
ans = 0
visited = [0 for _ in range(N)]
dfs(0, 0)
print(ans)