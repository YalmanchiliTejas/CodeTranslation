n, m = map(int, input().split())
conn = []

for _ in range(n):
    conn.append([False]*n)

visited = [False] * n

v = []

for _ in range(m):
    line = map(int, input().split())
    v.append([x-1 for x in line])

for start, end in v:
    conn[start][end] = conn[end][start] = True

def dfs(now, depth):
    if visited[now] : return 0
    if depth == n - 1: return 1

    visited[now] = True
    ret = 0

    for i in range(n):
        if conn[now][i]: ret += dfs(i, depth+1)

    visited[now] = False
    return ret

print(dfs(0, 0))