h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
x, y = [], []
for i in range(h):
    c = 0
    for j in range(w):
        if a[i][j] == "#":
            c = 1
            break
    if c == 0:
        x.append(i)
for i in range(w):
    c = 0
    for j in range(h):
        if a[j][i] == "#":
            c = 1
            break
    if c == 0:
        y.append(i)
for i in range(h):
    if not i in x:
        for j in range(w):
            if not j in y:
                print(a[i][j], end = "")
        print()