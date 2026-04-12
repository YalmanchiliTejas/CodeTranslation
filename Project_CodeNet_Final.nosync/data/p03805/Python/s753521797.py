def dfs(v, n, visited, t):
    if sum(visited) == n:
        return 1
    ret = 0
    for i in range(n):
        if [v,i] not in t:
            continue
        if visited[i]:
            continue
        visited[i] = 1
        ret += dfs(i, n, visited, t)
        visited[i] = 0
    return ret


n,m = map(int,input().split())
t = []
for _ in range(m):
    a,b = map(int,input().split())
    t.append([a-1, b-1])
    t.append([b-1, a-1])
visited = [0 for i in range(n)]
visited[0] = 1
print(dfs(0, n, visited, t))
