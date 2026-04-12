N, M = [int(_) for _ in input().split()]
ab = [[int(_) - 1 for _ in input().split()] for _ in range(M)]

G = [[0] * N for _ in range(N)]

for a, b in ab:
    G[a][b] = 1
    G[b][a] = 1

count = 0


def dfs(G, a, x):
    a[x] = 1
    if all(a):
        return 1
    else:
        count = 0
        for j in range(N):
            if G[x][j] == 1 and a[j] == 0:
                count += dfs(G, a.copy(), j)
        return count


print(dfs(G, [0] * N, 0))
