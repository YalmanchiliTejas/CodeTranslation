def dfs(g, v, i):
    if len(v) == len(g) - 1:
        return 1
    v.add(i)
    c = 0
    for u in g[i]:
        if u not in v:
            c += dfs(g, v, u)
    v.remove(i)
    return c


n, m = map(int, input().split())
tree = [list() for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    tree[a - 1].append(b - 1)
    tree[b - 1].append(a - 1)

print(dfs(tree, set(), 0))