n, m = map(int, input().split())
cs = [[0] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    cs[a][b] = 1
    cs[b][a] = 1
visited = [False] * (n + 1)
visited[0] = visited[1] = True


def dfs(k):
    count = 0
    es = [i for i in range(n + 1) if cs[k][i] == 1 and not visited[i]]
    if len(es) == 0:
        return 1 if all(visited) else 0
    for i in es:
        visited[i] = True
        count += dfs(i)
        visited[i] = False
    return count


print(dfs(1))