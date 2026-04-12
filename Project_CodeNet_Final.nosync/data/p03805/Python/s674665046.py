n, m = map(int, input().split())
graph = {i: [] for i in range(1, n + 1)}
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def dfs(i):
    ret = 0
    if all(han):
        return 1
    for j in range(1, n + 1):
        if han[j] == False and j in graph[i]:
            han[j] = True
            ret += dfs(j)
            han[j] = False
    return ret

han = [False] * (n + 1)
han[0] = True
han[1] = True
ans = dfs(1)
    
print(ans)