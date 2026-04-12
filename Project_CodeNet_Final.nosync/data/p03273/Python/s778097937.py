H, W = map(int, input().split())
a = [input() for i in range(H)]

rows = set()
cols = set()
for j in range(W):
    for i in range(H):
        if a[i][j] == '#':
            rows.add(i)
            cols.add(j)
for j in rows:
    for i in cols:
        print(a[j][i], end='')
    print('')
