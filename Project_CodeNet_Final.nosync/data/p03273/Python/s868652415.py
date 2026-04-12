H, W = map(int, input().split())
grid = [input() for i in range(H)]
grid2 = []
grid3 = []

for j in range(len(grid[0])):
    is_all_white = True
    column = []
    for i in range(len(grid)):
        column.append(grid[i][j])
        if grid[i][j] != ".":
            is_all_white = False
    if(not is_all_white):
        grid2.append(column)

for j in range(len(grid2[0])):
    is_all_white = True
    column = []
    for i in range(len(grid2)):
        column.append(grid2[i][j])
        if grid2[i][j] != ".":
            is_all_white = False
    if(not is_all_white):
        grid3.append(column)

for i in grid3:
    print("".join(i))