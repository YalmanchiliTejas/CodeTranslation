n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visit = [0] * (n + 1)
ans = 0


def dfs(now, depth):
    global ans
    if visit[now]:
        pass
    if depth == n:
        ans += 1

    visit[now] = 1
    if graph[now]:
        for i in graph[now]:
            if visit[i] == 0:
                dfs(i, depth + 1)
    visit[now] = 0


dfs(1, 1)
print(ans)
