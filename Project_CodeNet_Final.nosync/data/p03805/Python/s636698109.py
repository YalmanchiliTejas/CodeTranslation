N, M = map(int, input().split())
g = [[] for _ in range(N + 1)]
for _ in range(M):
    x, y = map(int, input().split())
    g[x].append(y)
    g[y].append(x)

ans = 0
todo = [(1, list(range(2, N + 1)))]
while todo:
    p, r = todo.pop()
    for np in g[p]:
        if np in r:
            if len(r) == 1:
                ans += 1
            else:
                nr = r[:]
                nr.remove(np)
                todo.append((np, nr))
print(ans)