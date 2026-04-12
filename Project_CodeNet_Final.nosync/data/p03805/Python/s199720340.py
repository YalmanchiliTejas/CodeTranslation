N, M = map(int, input().split())

v = []

for i in range(M):
    line = map(int, input().split())
    v.append([x - 1 for x in line])

conn = []
for _ in range(N):
    conn.append([False] * N)

visited = [False] * N

for start, end in v:
    conn[start][end] = conn[end][start] = True

def dfs(now, depth):
    if visited[now]:
        return 0
    if depth == N - 1:
        return 1

    visited[now] = True
    ret = 0

    for i in range(N):
        if conn[now][i]:
            ret += dfs(i, depth + 1)
    
    visited[now] = False

    return ret

print(dfs(0,0))