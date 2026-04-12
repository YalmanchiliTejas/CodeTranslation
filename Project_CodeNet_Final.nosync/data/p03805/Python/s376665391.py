def dfs(v, path):
    path.append(v)
    if len(path) == n:
        path.pop()
        return 1
    ans = 0
    for u in links[v]:
        if u in path:
            continue
        ans += dfs(u, path)
    path.pop()
    return ans


n, m = map(int, input().split())
links = [set() for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    links[a].add(b)
    links[b].add(a)
print(dfs(0, []))
