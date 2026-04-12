h, w = map(int, input().split())
li = [['x']*(w+2)]
li += [list('x' + input() + 'x') for _ in range(h)]
li += [['x']*(w+2)]

x = 1
y = 1

flag = 1
while flag:
    li[y][x] = 'o'

    if li[y][x+1] == '#':
        x += 1
    elif li[y+1][x] == '#':
        y += 1
    else:
        break

for i in range(h+2):
    for j in range(w+2):
        if li[i][j] == '#':
            print('Impossible')
            break
    else:
        continue
    break
else:
    print('Possible')