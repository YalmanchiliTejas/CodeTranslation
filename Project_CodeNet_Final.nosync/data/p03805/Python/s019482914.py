N, M = [int(v) for v in input().split()]
tbl = [[0] * (N + 1) for _ in range(N+1)]
for _ in range(M):
    a, b = [int(v) for v in input().split()]
    tbl[a][b] = 1
    tbl[b][a] = 1

ans = 0
paths = [[1, ]]
while paths:
    p = paths.pop()

    for i in range(1, N + 1):
        if p[-1] == i: continue
        if tbl[p[-1]][i] and i not in p:
            np = p + [i]
            if len(np) == N:
                ans += 1
            paths.append(np)
print(ans)