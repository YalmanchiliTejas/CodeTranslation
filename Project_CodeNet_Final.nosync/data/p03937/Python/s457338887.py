H,W = map(int, raw_input().split())
A = [list(raw_input()) for _ in range(H)]

x,y = 0,0
while (x!=W-1 or y!=H-1):
    A[y][x] = "."
    r = x<W-1 and A[y][x+1]=="#"
    d = y<H-1 and A[y+1][x]=="#"

    if int(r)+int(d)!=1:
        print "Impossible"
        exit(0)
    if r:
        x += 1
    if d:
        y += 1

if sum(a.count("#") for a in A)!=1:
    print "Impossible"
    exit(0)
print "Possible"
