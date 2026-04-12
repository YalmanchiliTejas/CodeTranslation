h,w = map(int,input().split())
grid = []
curh = h
curw = w
for i in range(h):
    grid.append(list(input()))
i = 0
while i < curh:
    if grid[i] == ["."]*curw:
        for j in range(i,curh-1):
            grid[j] = grid[j+1]
        grid.pop(curh-1)
        curh -= 1
        i -= 1
    i += 1
i = 0
while i < curw:
    for j in range(curh):
        if grid[j][i] == "#":
            break
    else:
        for j in range(curh):
            for k in range(i,curw-1):
                grid[j][k] = grid[j][k+1]
            grid[j].pop(curw-1)
        curw -= 1
        i -= 1
    i += 1
for i in range(curh):
    print("".join(grid[i]))