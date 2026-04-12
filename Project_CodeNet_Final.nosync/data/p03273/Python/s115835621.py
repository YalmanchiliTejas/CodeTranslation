h,w = map(int,input().split())
a = [list(input()) for i in range(h)]
hl = [0] * h
wl = [0] * w
for i in range(h):
    if '#' in a[i]:
        hl[i] = 1
        for j in range(w):
            if a[i][j] == '#':
                wl[j] = 1

for i in range(h):
    t = []
    for j in range(w):
        if  hl[i] == 1 and wl[j] == 1:
            t.append(a[i][j])
    if len(t) != 0:
        print(''.join(t))  