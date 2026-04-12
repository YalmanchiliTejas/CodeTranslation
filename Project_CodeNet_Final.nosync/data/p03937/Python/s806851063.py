h,w = map(int,input().split())
a = []
for i in range(h):
    s=list(input())
    a.append(s)

x = 0
y = 0

c = 0
a[0][0] = '.'
while x != w-1 or y != h-1:
    r = 0
    if x <= w-2:
        if a[y][x+1] == '#':
            r = 1
            a[y][x+1] = '.'
    if y <= h-2:
        if a[y+1][x] == '#':
            r += 2
            a[y+1][x] = '.'
    if x >= 1:
        if a[y][x-1] == '#':
            r = 0
    if y >= 1:
        if a[y-1][x] == '#':
            r = 0
    if r == 2:
        y += 1
    if r == 1:
        x += 1
    if x == w-1 and y == h-1:
        if a[y-1][x] == '.' and a[y][x-1] == '.':
            c = 1
    if r == 0 or r == 3:
        c = -1
        x = w-1
        y = h-1

    

    
if c == 1:
    print('Possible')
else:
    print('Impossible')