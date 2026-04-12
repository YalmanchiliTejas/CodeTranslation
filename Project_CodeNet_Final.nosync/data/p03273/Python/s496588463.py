h,w = map(int, raw_input().split())
m = [ raw_input() for _ in range(h) ]
hl = [ True for _ in range(h) ]
wl = [ True for _ in range(w) ]
for y in range(h):
    for x in range(w):
        if m[y][x] == '#':
            hl[y] = False
            wl[x] = False
for y in range(h):
    if hl[y]:
        continue
    s = ""
    for x in range(w):
        if wl[x]:
            continue
        s += m[y][x]
    print s
