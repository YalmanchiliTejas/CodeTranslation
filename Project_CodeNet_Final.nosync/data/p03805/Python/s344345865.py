from itertools import permutations

n, m = map(int, input().split())
g = {i: set() for i in range(1, n+1)}

for _ in range(m):
    a, b = map(int, input().split())
    g[a].add(b)
    g[b].add(a)

res = 0
visited = {1}
def dfs(v):
    global res
    global visited
    if len(visited) == n:
        res += 1
        return
    for i in g[v] - visited:
        visited.add(i)
        dfs(i)
        visited.remove(i)

dfs(1)

print(res)