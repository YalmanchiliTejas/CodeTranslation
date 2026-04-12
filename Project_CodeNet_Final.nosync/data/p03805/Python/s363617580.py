n, m = map(int, input().split())

graph = {i:[] for i in range(1, n+1)}
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * (n+1)

stack = [(1, 1, visited)]

count = 0
while stack:
    now, dist, visited_ = stack.pop()
    visited = visited_.copy()
    visited[now] = True
    if dist == n:
        count += 1
    for neighbor in graph[now]:
        if not visited[neighbor]:
            stack.append((neighbor, dist + 1, visited))

print(count)
