n, m = map(int, input().split())

g = [[0 for _ in range(n)] for _ in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a][b] = 1
    g[b][a] = 1

#print(g)

ans = 0
visited = [0 for _ in range(n)]

def dfs(v):
    visited[v] = 1
    if all(x == 1 for x in visited):
        global ans
        ans += 1
        return

    for i in range(n):
        if g[v][i] == 1 and visited[i] == 0:
            visited[i] = 1
            dfs(i)
            visited[i] = 0

    return

dfs(0)
print(ans)
