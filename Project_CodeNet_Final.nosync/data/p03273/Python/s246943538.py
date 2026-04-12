H, W = map(int, input().split())
Ai = [input() for _ in range(H)]

removable_y = [i for i in range(H)]
removable_x = [i for i in range(W)]

for y in range(H):
    removable = True
    for x in range(W):
        if Ai[y][x] != ".":
            removable = False
            break
    if not removable:
        removable_y.remove(y)

for x in range(W):
    removable = True
    for y in range(H):
        if Ai[y][x] != ".":
            removable = False
            break
    if not removable:
        removable_x.remove(x)

removable_x.reverse()
removable_y.reverse()

for y in removable_y:
    Ai = Ai[:y] + Ai[y + 1:]
for i in range(len(Ai)):
    txt = Ai[i]
    for x in removable_x:
        txt = txt[:x] + txt[x + 1:]
    Ai[i] = txt

for a in Ai:
    print(a)