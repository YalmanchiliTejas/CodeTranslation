h,w = map(int, raw_input().split())
m = [raw_input() for _ in range(h)]
possible = True
for y in range(h):
    for x in range(w):
        if m[y][x] == '#':
            p = 0
            if y > 0 and m[y-1][x] == '#':
                p += 1
            if x > 0 and m[y][x-1] == '#':
                p += 1
            if not(y == 0 and x == 0) and p != 1:
                possible = False
                break
            n = 0
            if y < h-1 and m[y+1][x] == '#':
                n += 1
            if x < w-1 and m[y][x+1] == '#':
                n += 1
            if not(y == h-1 and x == w-1) and n != 1:
                possible = False
                break
    if not possible:
        break
if possible:
    print 'Possible'
else:
    print 'Impossible'
