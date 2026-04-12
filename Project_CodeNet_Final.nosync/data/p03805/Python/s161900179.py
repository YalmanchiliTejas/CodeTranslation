from itertools import permutations

n, m = [int(i) for i in input().split()]
g = [[False] * n for i in range(n)]
for i in range(m):
    a, b = [int(i) - 1 for i in input().split()]
    g[a][b] = g[b][a] = True

ans = 0
for i in permutations(list(range(n)), n):
    if i[0] != 0:
        break

    for j in range(n):
        if j == n - 1:
            ans += 1
            break
        if not g[i[j]][i[j+1]]:
            break

print(ans)
