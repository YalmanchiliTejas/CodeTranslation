h, w = map(int, input().split())
a = [input() for _ in range(h)]

vrows = {r: False for r in range(h)}
vcols = {c: False for c in range(w)}

for r in range(h):
    for c in range(w):
        if a[r][c] == '#':
            vrows[r] = True
            vcols[c] = True

for r in range(h):
    if vrows[r]:
        row = ''
        for c in range(w):
            if vcols[c]:
                row += a[r][c]
        print(row)
