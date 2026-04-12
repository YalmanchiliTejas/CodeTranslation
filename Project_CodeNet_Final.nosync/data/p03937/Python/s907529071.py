h, w = [int(i) for i in input().split()]
grid = []
for _ in range(h):
    grid.append(list(input()))

x = 0
y = 0
while x < h or y < w:
    if x < h - 1 and grid[x + 1][y] == "#":
        grid[x][y] = "."
        x += 1
    elif y < w - 1 and grid[x][y + 1] == "#":
        grid[x][y] = "."
        y += 1
    else:
        break

if x != h - 1 or y != w - 1:
    print("Impossible")
else:
    grid[x][y] = "."
    for line in grid:
        if "#" in line:
            print("Impossible")
            quit()
    print("Possible")
