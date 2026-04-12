h, w = map(int, input().split())
a = [list(input()) for i in range(h)]

f_row = []
f_col = []
for i in range(h):
    for j in range(w):
        if a[i][j] != '.':
            break
        if j == w-1:
            f_row.append(i)
for j in range(w):
    for i in range(h):
        if a[i][j] != '.':
            break
        if i == h-1:
            f_col.append(j)

for i in range(h):
    if i in f_row:
        continue
    for j in range(w):
        if j not in f_col:
            print(a[i][j], end='')
    print()
