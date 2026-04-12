#!/usr/bin/env python3
n, m = map(int, input().split())
g = [[] for i in range(n)]
for i in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    g[a].append(b)
    g[b].append(a)


def dfs(used, s):
    global ans
    used[s] = True
    for t in g[s]:
        if not used[t]:
            dfs(used[:], t)
    if all(used):
        ans += 1


used = [False] * n
ans = 0
dfs([False] * n, 0)
print(ans)
