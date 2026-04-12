from itertools import permutations

n, m = list(map(int, input().split()))
mat = [[False] * n for i in range(n)]
for i in range(m):
    a, b = list(map(int, input().split()))
    mat[a - 1][b - 1] = mat[b - 1][a - 1] = True
ans = 0
for pat in permutations(range(n)):
    if pat[0] != 0:
        continue
    f = True
    for i in range(n - 1):
        if not mat[pat[i]][pat[i + 1]]:
            f = False
    if f:
        ans += 1
print(ans)