H,W = map(int,input().split())
m = []
k = 0
for _ in range(H):
    a = list(input())
    k += a.count('#')
    m.append(a)
if k == H+W-1:
    sx = sy = 0
    for i in range(H+W-1):
        if   (sx+1<W) and (m[sy][sx+1] == '#'):sx += 1
        elif (sy+1<H) and (m[sy+1][sx] == '#'):sy += 1
        else:
            if (sx==W-1) and (sy==H-1):print('Possible')
            else:print('Impossible',sx,sy)
            exit(0)
else:
    print('Impossible')