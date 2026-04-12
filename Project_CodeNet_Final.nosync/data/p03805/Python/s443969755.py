# C. One-stroke Path
# https://atcoder.jp/contests/abc054/tasks/abc054_c

from collections import deque

def dfs(i, visited):
    stack = deque()
    total = 0
    stack.append((i, visited))
    while stack:
        idx, vis = stack.popleft()
        if all(vis):
            total += 1
        for j in graph[idx]:
            if not vis[j]:
                v = vis[:]
                v[j] = True
                stack.append((j, v))
    return total

N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

visited = [False] * N
visited[0] = True
print(dfs(0, visited))

