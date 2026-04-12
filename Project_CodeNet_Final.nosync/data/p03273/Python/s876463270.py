h, w = map(int, input().split())
a = [list(input()) for i in range(h)]

tate = []
yoko = []
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            yoko.append(i)
            tate.append(j)

for i in range(h):
    for j in range(w):
        if i in yoko and j in tate:
            print(a[i][j], end="")
    if i in yoko:
        print()
