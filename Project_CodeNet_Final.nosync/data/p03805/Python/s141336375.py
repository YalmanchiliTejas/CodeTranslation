from itertools import permutations
N, M = map(int, input().split())
E = [[False]*N for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    E[a][b] = E[b][a] = True
ans = 0
for t in permutations(range(1, N)):
    pv = 0
    for v in t:
        if not E[pv][v]:
            break
        pv = v
    else:
        ans += 1
print(ans)
