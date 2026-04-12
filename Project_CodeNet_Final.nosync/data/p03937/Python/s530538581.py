import sys


inint = lambda: int(sys.stdin.readline())
inintm = lambda: map(int, sys.stdin.readline().split())
inintl = lambda: list(inintm())
instrm = lambda: map(str, sys.stdin.readline().split())
instrl = lambda: list(instrm())

h, w = inintm()
grid = []
now = [0,0]
fw = 0
fh = 0

for i in range(h):
    grid.append(input())

while now != [h-1,w-1]:
    if now[0] == h-1:
        if fh == 0 and now[1] != 0:
            if grid[h-1][now[1]+1] == "#" and grid[h-1][now[1]-1] == ".":
                now = [h-1, now[1]+1]
                fh = 1
        else:
            if grid[h-1][now[1]+1] == "#":
                now = [h-1, now[1]+1]
                fh = 1
            else:
                print("Impossible")
                exit()
    elif now[1] == w-1:
        if fw == 0 and now[0] != 0:
            if grid[now[0]+1][w-1] == "#" and grid[now[0]-1][w-1] == ".":
                now = [now[0]+1, w-1]
                fw = 1
            else:
                print("Impossible")
                exit()
        else:
            if grid[now[0]+1][w-1] == "#":
                now = [now[0]+1, w-1]
                fw = 1
            else:
                print("Impossible")
                exit()
    else:
        if grid[now[0]+1][now[1]] == "#" and grid[now[0]][now[1]+1] == ".":
            now = [now[0]+1, now[1]]
        elif grid[now[0]+1][now[1]] == "." and grid[now[0]][now[1]+1] == "#":
            now = [now[0], now[1]+1]
        else:
            print("Impossible")
            exit()

if fh == 0 and grid[h-1][w-2] == "#" and (h >= 2 and w >= 2):
    print("Impossible")
    exit()

print("Possible")