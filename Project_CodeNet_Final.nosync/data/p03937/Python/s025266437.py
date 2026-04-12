H,W = map(int,input().split())
grid = []
for i in range(H):
    grid.append(input())

current = (0,0)
good = True
for y in range(H):
    for x in range(W):
        if grid[y][x] == "#":
            count = 0
            aboveCount = 0
            if W-1>x and grid[y][x+1] == "#":
                count+=1
            if H-1>y and grid[y+1][x] == "#":
                count+=1
            if x>0 and grid[y][x-1] == "#":
                aboveCount+=1
            if 0<y and grid[y-1][x] == "#":
                aboveCount+=1
            if (aboveCount==0 and y+x!=0) or (count!=1 and y+x!=H+W-2):
                good = False
                break
if good:
    print("Possible")
else:
    print("Impossible")
