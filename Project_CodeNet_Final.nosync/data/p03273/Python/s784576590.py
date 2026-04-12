h,w = list(map(int, input().split()))
a = [input() for _ in range(h)]

compress_row = []

for i in range(h):
    if '#' not in a[i]:
        compress_row.append(i)

compress_col = []
for i in range(w):
    for j in range(h):
        if a[j][i] == '#':
            break
    else:
        compress_col.append(i)

row = []
for i in range(h):
    col = []
    for j in range(w):
        if j in compress_col:
            continue
        col.append(a[i][j])
    if i in compress_row:
        continue
    row.append(col)

print(*[''.join(r) for r in row], sep='\n')