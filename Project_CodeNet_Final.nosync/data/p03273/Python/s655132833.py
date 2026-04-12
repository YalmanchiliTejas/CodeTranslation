h, w = map(int, input().split())
a = [input() for _ in range(h)]
r = [False]*h
c = [False]*w
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            r[i] = True
            c[j] = True
for i in range(h):
    if r[i]:
        for j in range(w):
            if c[j]:
                print(a[i][j], end = "")
        print()