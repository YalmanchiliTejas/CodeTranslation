from itertools import permutations

N, M = map(int, input().split())
INF = 10**18
matrix = [[INF]*N for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    matrix[a][b] = 1
    matrix[b][a] = 1

ans = 0


for p in permutations(range(1, N)):
    ok = True
    cur = 0
    for pi in p:
        if matrix[cur][pi] == INF:
            ok = False
            break
        cur = pi
    if ok:
        ans += 1

print(ans)
