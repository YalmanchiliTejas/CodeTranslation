h,w=map(int,input().split())
a = [list(input()) for _ in range(h)]
a[0][0] = "."
q=[(0,0)]
dy=[0,1]
dx=[1,0]
while len(q)>0:
    y,x=q.pop(0)
    if y == h-1 and x == w-1:
        break
    for i in range(2):
        if not (0<=dy[i]+y<h and 0<=dx[i]+x<w):
            continue
        if a[dy[i]+y][dx[i]+x] != "#":
            continue
        else:
            a[dy[i]+y][dx[i]+x] = "."
            q.append((dy[i]+y,dx[i]+x))
            break
f = True
for i in range(h):
    for j in range(w):
        #print(a[i][j])
        if a[i][j] == "#":
            f = False
if f:
    print("Possible")
else:
    print("Impossible")