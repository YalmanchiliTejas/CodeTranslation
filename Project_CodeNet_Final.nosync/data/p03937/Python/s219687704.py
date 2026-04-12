H, W = map(int, input().split())
a = [input() + '.' for _ in range(H)]
a.append('.' * W)

seen = [[False for i in range(W)] for j in range(H)]
h, w = 0, 0
while h < H and w < W:
    seen[h][w] = True

    if a[h][w + 1] == a[h + 1][w]:
        print('Impossible')
        exit()

    if a[h][w + 1] == '#':
        w += 1
    else:
        h += 1

    if a[h - 1][w] == '#' and a[h][w - 1] == '#':
        print('Impossible')
        exit()

    if h == H - 1 and w == W - 1:
        print('Possible')
        exit()
print('Impossible')
