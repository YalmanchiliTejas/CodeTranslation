n = int(input())
a = tuple(map(int, input().split()))

memo = tuple([None] * n for _ in range(n))
for i, aa in enumerate(a):
    memo[i][i] = aa

for l in range(n - 1, -1, -1):
    for r in range(l, n):
        if memo[l][r] is None:
            memo[l][r] = max(a[r] - memo[l][r - 1], a[l] - memo[l + 1][r])

print(memo[0][n - 1])
