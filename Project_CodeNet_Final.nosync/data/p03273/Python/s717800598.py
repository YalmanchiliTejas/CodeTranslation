h,w = map(int, input().split())

a = [input() for i in range(h)]

row = [False] * h
col = [False] * w

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            row[i] = True
            col[j] = True

for i in range(h):
    if row[i] == True:
        for j in range(w):
            if col[j] == True:
                print(a[i][j],end = '')
        print()