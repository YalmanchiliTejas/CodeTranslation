from itertools import permutations

n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

g = [[0] * n for _ in range(n)]
for a, b in ab:
    a -= 1
    b -= 1
    g[a][b] = 1
    g[b][a] = 1

ans = 0
for pat in permutations(range(1, n), n - 1):
    is_path = True
    u = 0
    for v in pat:
        if g[u][v] == 0:
            is_path = False
        u = v

    if is_path:
        ans += 1

print(ans)
