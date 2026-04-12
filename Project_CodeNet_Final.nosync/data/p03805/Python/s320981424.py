# -*- coding: utf-8 -*-
n, m = [int(x) for x in input().split()]
adj = [[0]*n for i in range(n)]
visited = [0]*n
for i in range(m):
    a, b = [int(x) for x in input().split()]
    adj[a-1][b-1] = 1
    adj[b-1][a-1] = 1

ans = 0
def dfs(v):
    global ans
    if sum(visited) == n:
        ans += 1
    for i in range(n):
        if adj[v-1][i] == 1 and visited[i] == 0:
            visited[i] = 1
            dfs(i+1)
            visited[i] = 0

visited[0] = 1
dfs(1)
print(ans)