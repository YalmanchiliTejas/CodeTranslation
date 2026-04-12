h,w = map(int, input().split())
a = [list(input()) for _ in range(h)] # a[h][w]

row, col = [False]*h, [False]*w
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            row[i], col[j] = True, True
for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(a[i][j], end='')
        print()