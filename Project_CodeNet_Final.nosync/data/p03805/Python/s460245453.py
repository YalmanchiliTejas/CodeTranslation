from itertools import combinations, permutations
def inpl(): return list(map(int, input().split()))

N, M = inpl()
G = [[0]*(N+1) for _ in range(N+1)]

for _ in range(M):
    a, b = inpl()
    G[a][b] = 1
    G[b][a] = 1

ans = 0
for X in permutations(range(2, N+1)):
    a = 1
    for i in range(N-1):
        b = X[i]
        if G[a][b] == 0:
            break
        a = b
    else:
        ans += 1

print(ans)
