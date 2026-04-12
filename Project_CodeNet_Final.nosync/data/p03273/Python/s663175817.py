H, W = map(int, input().split())
G = [list(input()) for _ in range(H)]
v = [g for g in G if g.count('.') != W]
for i in reversed(range(W)):
    chk = True
    for vv in v:
        if vv[i] == '#':
            chk = False
            break
    if chk:
        for vv in v:
            vv.pop(i)
for vv in v:
    print(''.join(vv))