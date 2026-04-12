ans = 0

def dfs(v, visited, d):
    visited[v] = 1
    if all(visited):
        global ans
        ans += 1
        return
    for node in d[v]:
        if visited[node]:
            continue
        else:
            dfs(node, visited[:], d)

n, m = map(int, input().split())
d = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a = a - 1
    b = b - 1
    d[a].append(b)
    d[b].append(a)
v = 0
visited = [0] * n
dfs(v, visited, d)
print(ans)