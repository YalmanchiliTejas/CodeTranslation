from itertools import permutations
N, M = map(int, input().split())
g = [[0] * N for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    g[a][b] = g[b][a] = 1

cnt = 0
for e in permutations(range(1, N)):
    for a, b in zip([0] + list(e[:-1]), e):
        if not g[a][b]:
            break
    else:
        cnt += 1
print(cnt)