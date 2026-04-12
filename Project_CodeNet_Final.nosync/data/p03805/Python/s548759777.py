N, M = map(int, input().split())
edge = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
def dfs(start,route):
    route.append(start)
    if len(route) == N:
        route.remove(start)
        return 1
    res = 0
    for i in edge[start]:
        if i not in route:
            res += dfs(i,route)
    route.remove(start)
    return res
print(dfs(0,[]))