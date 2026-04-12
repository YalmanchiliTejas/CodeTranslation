h, w = map(int, input().split())
field = [list(input()) for _ in range(h)]

cnt = 0
for i in range(h):
    for j in range(w):
        if field[i][j] == '#':
            cnt += 1

print('Possible' if cnt == h + w - 1 else 'Impossible')
