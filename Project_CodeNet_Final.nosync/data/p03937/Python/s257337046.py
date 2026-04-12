h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(input())

pos = (0, 0)
pre = 1
nxt = 0
while True:
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
    if pos==(w-1, h-1) and nxt==0 and pre==1:
        print('Possible')
        break
    if nxt!=1 or pre!=1:
        print('Impossible')
        break
    pre = 0
    nxt = 0