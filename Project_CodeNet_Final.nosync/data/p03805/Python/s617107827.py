N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a - 1].append(b - 1)
    G[b - 1].append(a - 1)

def dfs(n):
    global P
    seen[n] = 1
    for g in G[n]:
        if seen[g] == 0:
            dfs(g)
            seen[g] = 0
    if not 0 in seen:
        P += 1
P = 0
seen = [0] * N
dfs(0)
print(P)