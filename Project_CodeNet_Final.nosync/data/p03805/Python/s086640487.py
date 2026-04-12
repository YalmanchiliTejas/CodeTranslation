from itertools import permutations as perm

n, m = map(int, input().split())

path = [[False] * n for _ in range(n)]
for i in range(n):
    path[i][i] = True

for _ in range(m):
    ai, bi = map(int, input().split())
    a, b = ai - 1, bi - 1
    path[a][b] = True
    path[b][a] = True

ans = 0
for ps in perm(range(1, n)):
    fst = ps[0]
    if not path[0][fst]:
        continue
    check = [path[i][j] for (i, j) in zip(ps, ps[1:])]
    if all(check):
        ans += 1

print(ans)