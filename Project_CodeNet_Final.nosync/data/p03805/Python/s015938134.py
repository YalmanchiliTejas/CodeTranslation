import numpy as np

n, m = map(int, input().split())
g = [[] for i in range(n + 1)]
visited = np.zeros(n, dtype=np.bool)
ans = 0


def dfs(now):
    global ans
    if (visited == True).all():
        ans += 1
    for i in range(len(g[now])):
        next_n = g[now][i]
        if visited[next_n - 1] == False:
            visited[next_n - 1] = True
            dfs(next_n)
            visited[next_n - 1] = False


for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)
# print(g)
visited[0] = True
dfs(1)
print(ans)
