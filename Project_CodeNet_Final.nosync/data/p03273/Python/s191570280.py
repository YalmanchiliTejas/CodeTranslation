# ABC 107: B – Grid Compression
h, w = [int(s) for s in input().split()]
a = [input() for _ in range(h)]

rows = []
columns = []

for i in range(w):
    for j in range(h):
        if a[j][i] != '.':
            break
    else:
        columns.append(i)

for i in range(h):
    if a[i].count('#') == 0:
        rows.append(i)

for i in range(h):
    tmp = ''
    if i not in rows:
        for j in range(w):
            if j not in columns:
                tmp += a[i][j]
        print(tmp)