h, w = map(int,input().split())
stay_x = []
stay_y = []
grid = []

for y in range(h):
    a = input()
    grid.append(a)
    remove = True
    for x in range(w):
        if a[x] == "#":
            remove = False
            if x not in stay_x:
                stay_x.append(x)        
    if remove != True:
        stay_y.append(y)
stay_x.sort()
for y in stay_y:
    out = ""
    for x in stay_x:
        out += grid[y][x]
    print(out)