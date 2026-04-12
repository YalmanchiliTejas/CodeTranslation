from itertools import permutations

n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

patterns = list(permutations(range(n)))

g = [ [False for _ in range(n)] for _ in range(n) ]
for a, b in ab:
    g[a-1][b-1] = True
    g[b-1][a-1] = True

ans = 0
for p in patterns:
    if p[0] != 0:
        continue
    ok = True
    for i in range(n-1):
        if not g[p[i]][p[i+1]]:
            ok = False
    if ok:
        ans += 1
print(ans)
