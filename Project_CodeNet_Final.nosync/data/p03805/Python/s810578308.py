N, M = map(int, input().split())

G = {k: [] for k in range(N)}  # 0-indexed
for _ in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)


def dfs(p, arrived):
    if arrived == 2**N-1:
        return 1

    ret = 0
    for n in G[p]:
        if (arrived >> n) & 1 == 0:
            ret += dfs(n, arrived+2**n)
    return ret


arrived = 1
print(dfs(0, arrived))
