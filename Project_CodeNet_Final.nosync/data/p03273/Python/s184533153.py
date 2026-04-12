H,W = map(int,input().split())
a = [list(input()) for _ in range(H)]

tate,yoko = set(),set()
for i in range(H):
    t = True
    for j in range(W):
        if a[i][j] == "#":
            t = False
            break
    if t:
        tate.add(i)
for j in range(W):
    y = True
    for i in range(H):
        if a[i][j] == "#":
            y = False
            break
    if y:
        yoko.add(j)

ct = 0
for t in tate:
    a = a[:t-ct] + a[t+1-ct:]
    ct += 1

cy = 0
for y in yoko:
    for i in range(H-len(tate)):
        a[i] = a[i][:y-cy] + a[i][y+1-cy:]
    cy += 1

for i in range(H-len(tate)):
    print("".join(a[i]))
