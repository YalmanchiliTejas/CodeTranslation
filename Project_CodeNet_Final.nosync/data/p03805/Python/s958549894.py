from itertools import permutations
n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)
ans = 0
for order in permutations(range(1, n), n-1):
    seen = [False] * n
    seen[0] = True
    pre = 0
    for v in order:
        if v not in g[pre] or seen[v]:
            break
        pre = v
        seen[v] = True
    else:
        ans += 1
print(ans)