import copy
n, m = map(int, input().split())

graph = [list() for i in range(n+1)]
for i in range(m):
   a, b = map(int, (input().split()))
   graph[a] += [b]
   graph[b] += [a]

def dfs(visited, now):
    tv = copy.copy(visited)
    tv[now-1] = 1
    if all(tv) == 1:
        return 1

    count = 0
    for i in graph[now]:
        if tv[i-1] == 0:
            count += dfs(tv, i)
    return count

print(dfs([0] * n, 1))