h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(input())

pos = (0, 0)
pre = 1
nxt = 0
while pos!=(w-1, h-1):
    x, y = pos
    if x<w-1 and a[y][x+1]=='#':
        nxt += 1
        pos = (x+1, y)
    if y<h-1 and a[y+1][x]=='#':
        nxt += 1
        pos = (x, y+1)
    if x>0 and a[y][x-1]=='#':
        pre += 1
    if y>0 and a[y-1][x]=='#':
        pre += 1
    if nxt!=1 or pre!=1:
        print('Impossible')
        break
    pre = 0
    nxt = 0
else:
    tmp = 0
    for i in a:
        tmp += i.count('#')
    if tmp!=h+w-1:
        print('Impossible')
    else:
        print('Possible')