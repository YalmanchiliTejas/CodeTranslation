h, w = map(int, input().split())

a = []

for y in range(h):
    a.append([_ for _ in input()])

rem_x = []
rem_y = []

for y in range(h):
    fl = 0
    for x in range(w):
        if a[y][x] == '#':
            fl = 1
    if fl == 1:
        rem_y.append(y)

for x in range(w):
    fl = 0
    for y in range(h):
        if a[y][x] == '#':
            fl = 1
    if fl == 1:
        rem_x.append(x)

for y in rem_y:
    for x in rem_x:
        print(a[y][x],end='')
    print()
