from collections import defaultdict
N, M = map(int, input().split())

G = defaultdict(list)
for i in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

V = [0] * N
V[0] = 1
def dfs(n, V):
    if all([v == 1 for v in V]):
        return 1

    ans = 0
    for e in G[n]:
        if V[e] == 1:
            continue
        V[e] = 1
        ans += dfs(e, V)
        V[e] = 0
    
    return ans

print(dfs(0, V))