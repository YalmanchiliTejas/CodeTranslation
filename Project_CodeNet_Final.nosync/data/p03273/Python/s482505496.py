h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

r = [False for _ in range(h)]
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            r[i] = True
            break
c = [False for _ in range(w)]
for i in range(w):
    for j in range(h):
        if a[j][i] == '#':
            c[i] = True
            break
for i in range(h):
    if r[i]:
        s = ""
        for j in range(w):
            if c[j]:
                s += a[i][j]
        print(s)