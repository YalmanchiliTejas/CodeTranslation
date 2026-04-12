from itertools import permutations

n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

g = [[0] * (n + 1) for _ in range(n + 1)]
for a, b in ab:
    g[a][b] = 1
    g[b][a] = 1

ans = 0
for nxt in permutations(range(2, n + 1), n - 1):
    bl = 1
    u = 1
    for v in nxt:
        if not g[u][v]:
            bl = 0
            break
        u = v

    ans += bl

print(ans)
