def search(y,x,oy,ox,r):
    if y == h-1 and x == w-1:
        return r
    l = []
    for i,j in t:
        ny,nx = y+i,x+j
        if (0 <= ny < h and 0 <= nx < w) and not (ny == oy and nx == ox):
            if a[ny][nx] == "#":
                l.append((ny,nx))

    if 1 < len(l) or len(l) == 0:
        return r
    else:
        r.add((l[0][0],l[0][1]))
        return search(l[0][0],l[0][1],y,x,r)

h,w = map(int,input().split())
a = [list(input()) for i in range(h)]
t = ((0,1),(1,0))

s = search(0,0,0,0,set([(0,0),(h-1,w-1)]))
f = True
for i in range(h):
    for j in range(w):
        if a[i][j] == "#" and not (i,j) in s:
            print("Impossible")
            exit(0)
print("Possible")