N, M = map(int, input().split())
E = {i: [] for i in range(N)}
for _ in range(M):
    u, v = map(int, input().split())
    E[u-1].append(v-1)
    E[v-1].append(u-1)

q = [(0, [0])]
c = 0
while q:
    x, p = q.pop()

    if len(p) == N:
        c += 1

    for v in E[x]:
        if v in p:
            continue
        q.append((v, p + [v]))

print(c)
