n, m = [int(item) for item in input().split()]
ab = [[int(item) for item in input().split()] for _ in range(m)]
edge = [[] for _ in range(n)] 
for a, b in ab:
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)

ans = 0
def dfs(visited, v):
    global ans
    nvisited = visited[:]
    nvisited.append(v)
    if len(nvisited) == n:
        ans += 1
    for item in edge[v]:
        if item not in nvisited:
            dfs(nvisited, item) 

dfs([], 0)
print(ans)