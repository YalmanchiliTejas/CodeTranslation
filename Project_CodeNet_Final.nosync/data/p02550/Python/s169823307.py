N, X, M = map(int, input().split())

pt = [[0] * (M+100) for i in range(70)]
to = [[0] * (M+100) for i in range(70)]
for i in range(M+1):
    to[0][i] = (i*i) % M
    pt[0][i] = i

for i in range(65):
    for j in range(M+1):
        to[i+1][j] = to[i][to[i][j]]
        pt[i+1][j] = pt[i][j] + pt[i][to[i][j]]

ans = 0
for i in range(60):
    if (N>>i)&1:
        ans += pt[i][X]
        X = to[i][X]

print(ans)
