n, m = map(int, input().split())
g = {}
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g.setdefault(a, [])
    g[a].append(b)
    g.setdefault(b, [])
    g[b].append(a)

isVisited = [False]*n
isVisited[0] = True

def dfs(v: int) -> int:
    if all(isVisited):
        return 1

    ret = 0

    for i in g[v]:
        if isVisited[i]:
            continue

        isVisited[i] = True
        ret += dfs(i)
        isVisited[i] = False

    return ret

print(dfs(0))
