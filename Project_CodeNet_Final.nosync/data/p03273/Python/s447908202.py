h, w = map(int, input().split())
a = [list(input()) for i in range(h)]

r = set()
for i in range(h):
    ok = True
    for j in range(w):
        if a[i][j] == '#':
            ok = False
            break
    else:
        if ok:
            r.add(i)
c = set()
for j in range(w):
    ok = True
    for i in range(h):
        if a[i][j] == '#':
            ok = False
            break
    else:
        if ok:
            c.add(j)
for i in range(h):
    tmp = ''
    if i in r:
        continue
    for j in range(w):
        if j in c:
            continue
        tmp += a[i][j]
    print(tmp)
