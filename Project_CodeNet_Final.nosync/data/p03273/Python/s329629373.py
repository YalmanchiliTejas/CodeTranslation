H, W = map(int, input().split())
grid = []

for i in range(H):
    row = list(input())
    if "#" in row:
        grid.append(row)

h = len(grid)
for j in range(W):
    cnt = 0
    for i in range(h):
        if grid[i][j] == "#":
            cnt += 1
    if cnt <= 0:
        for i in range(h):
            grid[i][j] = "x"

for i in range(h):
    row = ""
    for j in range(W):
        if grid[i][j] != "x":
            row += grid[i][j]
    print(row)
