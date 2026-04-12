H, W = map(int, input().split())
field = [input() for _ in range(H)]
hi, wi = set(), set()
for i in range(H):
    if not('#' in field[i]):
        hi.add(i)
for i in range(W):
    f = False
    for j in range(H):
        if field[j][i] == '#':
            f = True
    if not f:
        wi.add(i)
for i in range(H):
    if i in hi:
        continue
    for j in range(W):
        if j in wi:
            continue
        print(field[i][j], end="")
    print("")
