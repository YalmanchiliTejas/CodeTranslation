from itertools import permutations

n, m = map(int, input().split())

g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

ans = 0
for perm in permutations(range(1, n), n-1):
    s = 0
    flag = True
    for p in perm:
        if p not in g[s]:
            flag = False
            break
        s = p
    if flag:
        ans += 1
print(ans)
