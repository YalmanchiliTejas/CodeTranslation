n, m = map(int, input().split())

a = [[0] * n for i in range(n)]

for i in range(m):
    b = list(map(int, input().split()))
    a[b[0]-1][b[1]-1] = 1
    a[b[1]-1][b[0]-1] = 1

def dfs(v, n, visited):
    all_visited = 1
    for i in range(n):
        if visited[i] == 0:
            all_visited = 0

    if all_visited == 1:
        return 1

    ret = 0
    for i in range(n):
        if a[v][i] == 0:
            continue
        if visited[i] == 1:
            continue

        visited[i] = 1
        ret += dfs(i, n, visited)
        visited[i] = 0

    return ret

visited = [0] * n
visited[0] = 1
print(dfs(0, n, visited))
