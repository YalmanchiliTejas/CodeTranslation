N, X, M = map(int, input().split())
N -= 1
L = 1
while 1 << L <= N:
    L += 1
table = [[None] * M for _ in range(L)]
for i in range(M):
    x = i * i % M
    table[0][i] = (x, x)
for i in range(1, L):
    for j in range(M):
        k, s = table[i-1][j]
        l, t = table[i-1][k]
        table[i][j] = (l, s + t)
ans = X
for i in range(L)[::-1]:
    if (1 << i) <= N:
        j, s = table[i][X]
        ans += s
        N -= (1 << i)
        X = j
print(ans)