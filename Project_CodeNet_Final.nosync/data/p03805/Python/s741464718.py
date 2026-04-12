n, m = map(int, input().split())
edge = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edge[a].append(b)
    edge[b].append(a)

# [[1, 2], [0, 2], [0, 1]]

visited = [0] * n

def dfs(current, prev):

    if sum(visited) == n:
        return 1

    res = 0

    for next in edge[current]:
        if next != prev and visited[next] == 0:
            visited[next] = 1
            res += dfs(next, current)
            visited[next] = 0
    
    return res

visited[0] = 1
ans = dfs(0, -1)
print(ans)