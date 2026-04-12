from itertools import permutations
N, M = map(int, input().split())
G = [[False] * (N + 1) for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a][b] = True
    G[b][a] = True

ans = 0
for p in permutations(range(2, N + 1)):
    bl = G[1][p[0]]
    for x, y in zip(p[:-1], p[1:]):
        bl &= G[x][y]
    ans += int(bl)

print(ans)