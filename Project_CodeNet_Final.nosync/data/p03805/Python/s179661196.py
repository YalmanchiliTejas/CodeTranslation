def dfs(v):
    if len(set(visited)) == 1 and visited[0]:
        return 1
    count = 0
    for p in points[v]:
        if not visited[p]:
            visited[p] = True
            count += dfs(p)
            visited[p] = False
    else:
        return count


n,m = [int(x) for x in input().split()]
points = [[] for _ in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    points[a-1].append(b-1)
    points[b-1].append(a-1)

visited = [False]*n
visited[0] = True

print(dfs(0))
