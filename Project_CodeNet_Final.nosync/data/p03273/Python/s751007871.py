h, w = map(int, input().split())
a = [[0] * w for i in range(h)]

for i in range(h):
    line = input()
    for j in range(w):
        a[i][j] = line[j]

delete_row = []
for i in range(h):
    chk = True
    for j in range(w):
        if a[i][j] == '#':
            chk = False
            break
    if chk:
        delete_row.append(i)

for row in delete_row[::-1]:
    a.pop(row)

delete_col = []
for i in range(w):
    chk = True
    for j in range(h-len(delete_row)):
        if a[j][i] == '#':
            chk = False
            break
    if chk:
        delete_col.append(i)

for row in a:
    for col in delete_col[::-1]:
        row.pop(col)

for i in a:
    for j in i:
        print(j, end='')
    print()