h,w = map(int, input().split())
a = []
yoko = [False]*h
tate = [False]*w
for i in range(h):
    a.append(list(str(input())))

for x in range(h):
    for y in range(w):
        if a[x][y] == '#':
            yoko[x] = True
            tate[y] = True

for x in range(h):
    if yoko[x]:
        for y in range(w):
            if tate[y]:
                print(a[x][y], end="")
        else:
            print("")
