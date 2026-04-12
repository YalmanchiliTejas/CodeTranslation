H, W = map(int, input().split())
a = [i for i in range(H)]

for i in range(H):
    a[i] = list(input())

row = []
column = []

for i in range(H):
    flag = True
    for j in range(W):
        if a[i][j] != '.':
            flag = False
            break
    if flag:
        row.append(i)

for j in range(W):
    flag = True
    for i in range(H):
        if a[i][j] != '.':
            flag = False
            break
    if flag:
        column.append(j)

for i in range(H):
    if i in row:
        continue
    for j in range(W):
        if j in column:
            continue
        print(a[i][j], end='')
    print('')