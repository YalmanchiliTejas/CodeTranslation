from itertools import permutations

n, m = map(int, input().split())
g = [[] for _ in range(n)]

for _ in range(m):
    a, b = map(lambda x: int(x)-1, input().split())
    g[a].append(b)
    g[b].append(a)

ans = 0

for p in permutations(range(1, n)):
    if p[0] not in g[0]: continue
    for i in range(n-2):
        if p[i+1] not in g[p[i]]: break
    else: ans += 1

print(ans)
