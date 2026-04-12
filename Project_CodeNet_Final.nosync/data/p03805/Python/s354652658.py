n, m = map(int, input().split())
edge = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edge[a].append(b)
    edge[b].append(a)


def dfs(v, seen, res):
    seen[v] = True
    if all(seen):
        res += 1

    for i in edge[v]:
        if not seen[i]:
            tmp = [tf for tf in seen]
            res = dfs(i, tmp, res)

    return res


visited = [False]*n
ans = dfs(0, visited, 0)
print(ans)
