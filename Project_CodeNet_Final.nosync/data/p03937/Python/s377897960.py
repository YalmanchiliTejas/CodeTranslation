h,w = map(int,input().split())
maze = [input() for _ in range(h)]
total = 0
for maz in maze:
    for m in maz:
        if m == "#":
            total += 1

ans = False
def search(x,y,count):
    global ans
    if x == w-1 and y == h-1 and maze[y][x] == "#" and total == count:
        ans = True
        return
    if x < w-1 and maze[y][x+1] == "#":
        search(x+1,y,count+1)
    if y < h-1 and maze[y+1][x] == "#":
        search(x,y+1,count+1)

if maze[0][0] == "#":
    search(0,0,1)
if ans:print("Possible")
else:print("Impossible")