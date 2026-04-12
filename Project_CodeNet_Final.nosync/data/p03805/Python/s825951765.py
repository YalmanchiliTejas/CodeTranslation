import itertools
N, M = map(int, input().split())
G = [[False]*10 for _ in range(10)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a][b] = G[b][a] = True

res = 0
L = list(itertools.permutations(range(N)))

for l in L:
    if l[0] != 0:
        break
    ok = True
    for i in range(N-1):
        from_ = l[i]
        to_ = l[i+1]
        if not G[from_][to_]:
            ok = False
    if ok:
        res += 1
print(res)
