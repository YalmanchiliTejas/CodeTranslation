H, W = map(int, input().split())
F = [input() for _ in range(H)]

row = []
for i in range(H):
    if '#' not in F[i]:
        row.append(i)

column = []
for j in range(W):
    if all([F[i][j] == '.' for i in range(H)]):
        column.append(j)

ans = ''
for i in range(H):
    ret = False
    for j in range(W):
        if i not in row and j not in column:
            ans += F[i][j]
            ret = True
    if ret:
        ans += '\n'
print(ans)