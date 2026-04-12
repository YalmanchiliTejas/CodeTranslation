#! /usr/bin/env python3

H, W = map(int, input().split())
F = [list(input()) for x in range(H)]
ans = True
px = py = 0
while py < H-1 or px < W-1:
    if py<H-1 and F[py+1][px]=='#':
        if (px<W-1 and F[py][px+1]=='#') or (px>0 and F[py+1][px-1]=='#'):
            ans = False
            break
        py += 1
    elif px<W-1 and F[py][px+1]=='#':
        if py>0 and F[py-1][px+1]=='#':
            ans = False
            break
        px += 1
    else:
        ans = False
        break
print('Possible' if ans else 'Impossible')