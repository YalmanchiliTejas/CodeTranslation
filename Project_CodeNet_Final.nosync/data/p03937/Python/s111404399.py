H,W = map(int,input().split())
src = [input() for i in range(H)]

x = y = p = 0
while x < W-1 or y < H-1:
    if x < W-1 and src[y][x+1] == '#':
        p += 1
        x += 1
    elif y < H-1 and src[y+1][x] == '#':
        p += 1
        y += 1
    else:
        print('Impossible')
        exit()

c = 0
for row in src:
    c += row.count('#')
print('Possible' if p+1==c else 'Impossible')