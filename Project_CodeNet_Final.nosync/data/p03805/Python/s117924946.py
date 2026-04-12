N, M = map(int, input().split())
AB = [tuple(map(int, input().split())) for _ in range(M)]
G = [[] for _ in range(N)]
for a, b in AB:
    G[a-1].append(b-1)
    G[b-1].append(a-1)
visited = [False] * N
visited[0] = True
ans = 0
def dfs(x):
    global ans
    if all(visited):
        ans += 1
        return
    for y in G[x]:
        if not visited[y]:
            visited[y] = True
            dfs(y)
            visited[y] = False
dfs(0)
print(ans)