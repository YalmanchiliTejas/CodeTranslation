h, w = map(int, input().split())
a = [list(input()) for x in range(h)]

row = [False]*h
col = [False]*w

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            col[j] = True
            row[i] = True

for x in range(h):
    if row[x]:
        for y in range(w):
            if col[y]:
                print(a[x][y], end='')
        print()
        