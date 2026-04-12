
from collections import deque
H, W = map(int, input().split())
sy,sx = 1,1
gy,gx = H,W
sy-=1
sx-=1
gy-=1
gx-=1
con = [[1,0],[0,1],[-1,0],[0,-1]]
m=[]
d = [[0]*W for _ in range(H)]
for i in range(H):
    a= input()
    m.append(a)
q = deque()
q.append((sy,sx))
d[sy][sx] = 1
s = 0
while len(q)>0:
    y,x = q.popleft()
    if y == gy and x == gx:
        break
    for dx,dy in con:
        if  y+dy>=0 and x+dx >= 0 and y+dy < H and x+dx < W:
            if d[y+dy][x+dx] == 0 and m[y+dy][x+dx] =="#":
                q.append((y+dy,x+dx))
                d[y+dy][x+dx]+=d[y][x]+1
for i in range(H):
    for j in range(W):
        if m[i][j] == "#":s+=1
if H+W < d[gy][gx] or s > d[gy][gx]:
    print("Impossible")
else:print("Possible")
