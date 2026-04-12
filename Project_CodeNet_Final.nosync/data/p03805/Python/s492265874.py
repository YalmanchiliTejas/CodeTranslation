n, m = map(int,input().split())
graph = [[] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

counter = 0
def dfs(pointer, already_visited):
    global counter
    if len(already_visited) == n - 1:
        counter += 1
    for el in graph[pointer]:
        if el in already_visited:
            continue
        dfs(el, already_visited + [pointer])

dfs(1, [])
print(counter)
