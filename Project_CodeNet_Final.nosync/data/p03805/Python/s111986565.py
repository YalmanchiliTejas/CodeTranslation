n, m = map(int, input().split())
g = [[] for i in range(n)]
for _ in range(m):
    a, b = map(lambda x:int(x) - 1, input().split())
    g[a].append(b)
    g[b].append(a)

def dfs(s, path):
    if len(path) == n:
        return 1
    cnt = 0
    for next in g[s]:
        if next in path:
            continue
        cnt += dfs(next, path + [next])
    return cnt

print(dfs(0, [0]))