import sys
input = sys.stdin.readline
n, m = [int(x) for x in input().strip().split()]
g = [[0] * n for _ in range(n)]
for i in range(m):
    a, b = [int(x) for x in input().strip().split()]
    g[a-1][b-1] = 1
    g[b-1][a-1] = 1

flags = [False] * n
def dfs(flags, v):
    if flags.count(False) == 1:
        return 1
    flags[v] = True
    ret = 0
    for i, f in enumerate(g[v]):
        if f == 0 or flags[i]:
            continue
        ret += dfs(flags[:], i)
    return ret

print(dfs(flags[:], 0))