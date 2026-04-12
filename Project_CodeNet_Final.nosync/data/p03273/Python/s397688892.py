h,w = map(int,input().split())
grid = [list(input()) for i in range(h)]
row = {}
col = {}

for i in range(h):
    if "#" in grid[i]:
        row[i] = True
    else:
        row[i] = False

for j in range(w):
    c = False
    for i in range(h):
        if grid[i][j] == "#":
            c = True
    else:
        if c:
            col[j] = True
        else:
            col[j] = False

for i in range(h):
    o = False
    for j in range(w):
        if row[i] and col[j]:
            print (grid[i][j], end="")
            o = True
            pass
        else:
            pass
    if o:
        print ()
