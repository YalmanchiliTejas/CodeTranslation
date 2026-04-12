N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    A, B = map(int, input().split())
    G[A - 1].append(B - 1)
    G[B - 1].append(A - 1)

path, ans = [[0]], 0
while len(path) > 0:
    p = path.pop()
    if len(p) == N:
        ans += 1
    else:
        for g in G[p[-1]]:
            if not g in p:
                path.append(p + [g])

print(ans)
