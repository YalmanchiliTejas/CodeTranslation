h, w = map(int, raw_input().split())
A = [list(raw_input()) for i in xrange(h)]

x = y = 0
A[0][0] = '.'
while 1:
    if y+1 < h and A[y+1][x] == '#':
        A[y+1][x] = '.'
        y += 1
    elif x+1 < w and A[y][x+1] == '#':
        A[y][x+1] = '.'
        x += 1
    else: break
if y == h-1 and x == w-1 and all(all(f is '.' for f in e) for e in A):
    print "Possible"
else:
    print "Impossible"
