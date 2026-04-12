n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]
edges = [[] for _ in range(n)]
for a, b in ab:
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)
reached = [False for i in range(n)]
def dfs(edge, r):
    if all(r):
        return 1
    ret = 0
    for e in edges[edge]:
        if r[e]:
            continue
        r[e] = True
        ret += dfs(e, r)
        r[e] = False
    return ret
reached[0] = True
print(dfs(0, reached))
