H, W = map(int, input().split())
a = [0 for _ in range(H)]

for i in range(H):
    a[i] = list(map(str, input()))

row = [False] * H
col = [False] * W

for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            row[i] = True
            col[j] = True

for i in range(H):
    if row[i]:
        for j in range(W):
            if col[j]:
                print(a[i][j], end = '')
        print()
