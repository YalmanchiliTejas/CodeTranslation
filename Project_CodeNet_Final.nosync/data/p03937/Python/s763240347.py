h, w = map(int, input().split())
a = [0] * h
for i in range(h):
    aa = list(input())
    a[i] = aa

x, y = 0, 0
px, py = 0, 0
while not (x == w-1 and y == h-1):
    if not (x == 0 and y == 0):
        if px == x and py == y:
            print('Impossible')
            exit()
    px, py = x, y
    # → を検索
    if not x+1 > w-1:
        if a[y][x+1] == '#':
            a[y][x] = '.'
            x += 1
            continue
    # ↓ を検索
    if not y+1 > h-1:
        if a[y+1][x] == '#':
            a[y][x] = '.'
            y += 1
            continue

ans = True

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            if i == h-1 and j == w-1:
                pass
            else:
                ans = False

if ans:
    print('Possible')
else:
    print('Impossible')