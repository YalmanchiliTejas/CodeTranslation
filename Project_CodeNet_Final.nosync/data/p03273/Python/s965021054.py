h, w = (int(v) for v in input().split())
a = [input() for _ in range(h)]

my = [True for _ in range(h)]
mx = [True for _ in range(w)]

for y in range(h):
    for x in range(w):
        if a[y][x] != '.':
            break
    else:
        my[y] = False

for x in range(w):
    for y in range(h):
        if a[y][x] != '.':
            break
    else:
        mx[x] = False

for y in range(h):
    for x in range(w):
        if my[y] and mx[x]:
            print(a[y][x], end='')
    if my[y]:
        print()