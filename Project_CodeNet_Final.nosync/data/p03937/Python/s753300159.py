from collections import deque
h, w =  map(int, input().split())
a = [list(input()) for i in range(h)]
mv = [[1, 0], [0, 1]]

sx, sy = 0, 0
gx, gy = h - 1, w - 1
nxt = deque()
nxt.appendleft([sx, sy])

for i in range(h - 1):
    count = 0
    check = 0
    count2 = 0
    for j in range(w):
        if a[i][j] == "#":
            if a[i][j] == a[i + 1][j]:
                count += 1
                if check == 0:
                    check = 1
                    if count2 > 0:
                        count = 2
                        break
        else:
            if a[i + 1][j] == "#":
              count2 += 1  

    if count > 1:
        nxt.clear()
        break

flag = 0
while len(nxt) > 0:
    tmp = nxt.pop()
    nwx, nwy = tmp[0], tmp[1]
    if nwx == gx and nwy == gy:
        flag = 1
        break
    count = 0
    for i in range(2):
        tmpx = mv[i][0] + nwx
        tmpy = mv[i][1] + nwy
        if tmpy < w and tmpx < h:
            if a[tmpx][tmpy] == '#':
                nxt.appendleft([tmpx, tmpy])
                count += 1
    if count > 1:
        break

if flag:
    print("Possible")
else:
    print("Impossible")