h, w = map(int, input().split())
a = [input() for _ in range(h)]

row = [False] * h # 行
col = [False] * w # 列

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            row[i] = True
            col[j] = True

for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(a[i][j], end = '')
        print()