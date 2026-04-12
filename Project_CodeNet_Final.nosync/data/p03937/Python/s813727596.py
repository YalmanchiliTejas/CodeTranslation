from collections import deque
h, w = map(int, input().split())
field = []
check = [[False for _ in range(w)] for _ in range(h)]
for i in range(h):
    s = list(input().strip())
    field.append(s)

sx, sy = 0, 0
d = deque()
dirx = [0, 1, 0, -1]
diry = [1, 0, -1, 0]
d.append([sx, sy])
# 離れ島がないかのチェック
while (d):
    nowx, nowy = d.popleft()
    check[nowx][nowy] = True
    for x, y in zip(dirx, diry):
        nx = nowx + x
        ny = nowy + y
        if nx in range(h) and ny in range(w) and (
                not check[nx][ny]) and field[nx][ny] == '#':
            d.append([nx, ny])
for i in range(h):
    for j in range(w):
        if not check[i][j] and field[i][j] == '#':
            print('Impossible')
            exit()

# 右or下のみの最短でいけるかチェック
d.append([sx, sy])
check = [[False for _ in range(w)] for _ in range(h)]
while (d):
    nowx, nowy = d.pop()
    check[nowx][nowy] = True

    for x, y in zip(dirx[0:2], diry[0:2]):
        nx = nowx + x
        ny = nowy + y
        if nx in range(h) and ny in range(w) and field[nx][ny] == '#':
            d.append([nx, ny])
    for x, y in zip(dirx[2:4], diry[2:4]):
        nx = nowx + x
        ny = nowy + y
        if nx in range(h) and ny in range(
                w) and field[nx][ny] == '#' and not check[nx][ny]:
            print('Impossible')
            exit()

    if len(d) == 2:
        print('Impossible')
        exit()
    if nowx == h - 1 and nowy == w - 1:
        print('Possible')
        exit()

print('Impossible')
