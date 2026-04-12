n,m = map(int, input().split())
link = [[] for i in range(n)]
for i in range(m):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    link[a].append(b)
    link[b].append(a)

visited = [0]*n
ans = 0

def dfs(now, prev):
    global ans

    if sum(visited) == n:
        ans += 1

    for i in link[now]:
        if i != now and visited[i] == 0:
            visited[i] = 1
            dfs(i, now)
            visited[i] = 0

visited[0] = 1
dfs(0,-1)
print(ans)