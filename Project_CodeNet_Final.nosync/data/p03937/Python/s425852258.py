def inpl():
    return list(map(int, input().split()))


H, W = inpl()
A = [list(input()) for i in range(H)]

x, y = 0, 0

while y != H - 1 or x != W - 1:
    A[y][x] = '.'
    dy, dx = min(y + 1, H - 1), x
    ry, rx = y, min(x + 1, W - 1)
    if A[dy][dx] == '#':
        y, x = dy, dx
    elif A[ry][rx] == '#':
        y, x = ry, rx
    else:
        # print(A)
        print('Impossible')
        break
else:
    A[H - 1][W - 1] = '.'
    if any('#' in a for a in A) is True:
        print('Impossible')
    else:
        print('Possible')
