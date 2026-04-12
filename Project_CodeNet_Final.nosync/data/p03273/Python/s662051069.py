def grid_compression(a, h, w):
    hh = []
    for i in range(h):
        ok = True
        for j in range(w):
            if a[i][j] == '#':
                ok = False
                break
        if ok:
            hh += [i]
    ww = []
    for i in range(w):
        ok = True
        for j in range(h):
            if a[j][i] == '#':
                ok = False
                break
        if ok:
            ww += [i]
    aa = []
    for i in range(h):
        if i in hh:
            continue
        aa.append('')
        for j in range(w):
            if j in ww:
                continue
            aa[-1] += a[i][j]
    return '\n'.join(aa)

h, w = map(int, input().split())
a = []
for _ in range(h):
    a += [list(input())]
print(grid_compression(a, h, w))
