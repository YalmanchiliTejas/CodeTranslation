h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

#print(a)

x = 0
y = 0
a[x][y] = '.'

while  x < h and y < w:
    #print(x, y)
    if x < h-1:
        if a[x+1][y] == '#':
            x += 1
            a[x][y] = '.'
            continue
    if y < w-1:
        if a[x][y+1] == '#':
            y += 1
            a[x][y] = '.'
            continue
    if x == h - 1 and y == w - 1:
        break
    else:
        print('Impossible')
        exit()

#for x in a: print(x)

for b in a:
    if '#' in b:
        print('Impossible')
        exit()


print('Possible')