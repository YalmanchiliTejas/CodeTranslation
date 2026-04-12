H, W = map(int, input().split())
f = [list(input()) for _ in range(H)]
Y, X = [False for _ in range(H)], [False for _ in range(W)]
for y in range(H):
    for x in range(W):
        Y[y] |= f[y][x] == '#'
        X[x] |= f[y][x] == '#'
for y in range(H):
    flag = False
    for x in range(W):
        if Y[y] and X[x]:
            print(f[y][x], end = "")
            flag = True
    if flag:
        print()