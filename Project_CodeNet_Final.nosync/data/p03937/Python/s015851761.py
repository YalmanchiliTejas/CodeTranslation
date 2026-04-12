
H, W = map(int, input().split())
m = [input() for i in range(H)]

cnt = 0
for h in range(H):
    for w in range(W):
        if m[h][w] == '#':
            cnt += 1

def rec(x, y):
    if x == W - 1 and y == H - 1:
        return True

    if m[y][x] != '#':
        return False
    dx = [0, 1]
    dy = [1, 0]

    for i in range(2):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx and nx < W and \
           0 <= ny and ny < H:
            ret = rec(nx, ny)
            if ret:
                return ret
    return False


if rec(0, 0) and cnt == H + W - 1:
    print("Possible")
else:
    print("Impossible")