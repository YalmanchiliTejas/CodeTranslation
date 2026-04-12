h, w = map(int, input().split())
a = [
    input().rstrip()
    for _ in range(h)
]

hh = []
for y in range(h):
    f = True
    for x in range(w):
        if a[y][x] == '#':
            f = False
            break
    if f:
        hh.append(y)

ww = []
for x in range(w):
    f = True
    for y in range(h):
        if a[y][x] == '#':
            f = False
            break
    if f:
        ww.append(x)

ans = []
for y in range(h):
    if y in hh:
        continue
    aa = ''
    for x in range(w):
        if x in ww:
            continue
        aa += a[y][x]
    ans.append(aa)

for aa in ans:
    print(aa)