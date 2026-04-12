import itertools

n, m = map(int, input().split())
am = [[False]*n for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    am[a-1][b-1] = True
    am[b-1][a-1] = True

ans = 0
for p in itertools.permutations(list(range(n)), n):
    if p[0] != 0:
        continue

    isok = True
    for i in range(len(p)-1):
        if not am[p[i]][p[i+1]]:
            isok = False
            break

    if isok:
        ans += 1

print(ans)
