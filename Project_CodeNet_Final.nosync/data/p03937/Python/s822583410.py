H, W = map(int, input().split())
A = []
for _ in range(H):
    A.append(list(input()))

cnt = 0
for y in range(H):
    for x in range(W):
        if A[y][x] == '#':
            cnt += 1

x, y = 0, 0
seen = 0
while 0 <= x < W and 0 <= y < H:
    #print(x, y)
    if 0 <= y < H - 1 and A[y + 1][x] == '#':
        y = y + 1
        seen += 1
    elif 0 <= x < W - 1 and A[y][x + 1] == '#':
        x = x + 1
        seen += 1
    elif x == W - 1 and y == H - 1:
        #print(cnt)
        if seen == cnt - 1:
            print('Possible')
            break
        else:
            print('Impossible')
            break
    else:
        print('Impossible')
        break


