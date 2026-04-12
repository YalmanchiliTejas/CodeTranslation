import itertools

N, M = map(int, input().split())
patterns = list(itertools.permutations(range(2, N+1)))
path = [[0]*(N+1) for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    path[a][b] = 1
    path[b][a] = 1

ans = 0
for pattern in patterns:
    p = 1
    ok = True
    for x in pattern:
        if path[p][x] == 0:
            ok = False
            break
        p = x
    if ok:
        ans += 1
print(ans)
