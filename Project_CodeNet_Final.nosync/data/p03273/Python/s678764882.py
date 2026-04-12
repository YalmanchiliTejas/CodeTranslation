import math
H,W=list(map(int,input().split()))
grid=[]
for i in range(H):
    grid.append(input())
after=[]
for i in range(H):
    if grid[i] != '.'*W:
        after.append(grid[i])

H = len(after)
W = len(after[0])

flag = []
for i in range(H):
    r = []
    for j in range(W):
        r.append(1)
    flag.append(r)

for j in range(W):
    c = ''
    for i in range(H):
        c = c+after[i][j]
    if c == '.'*H:
        for k in range(H):
            flag[k][j] = 0
            W -= 1
    else:
        pass
out=[]
for i in range(H):
    out.append([])

for i in range(H):
    for j in range(len(after[0])):
        if flag[i][j] == 1:
            out[i].append(after[i][j])
        else:
            pass

for i in range(H):
    print(''.join(out[i]))
