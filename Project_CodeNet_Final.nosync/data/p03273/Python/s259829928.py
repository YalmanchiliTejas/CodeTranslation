H, W = map(int, input().split())

grid = []
for _ in range(H):
    row = input()
    if row[0] == "." and len(set(row)) == 1:
        H -= 1
        continue
    grid.append(row)

for i in range(W-1, -1, -1):
    if grid[0][i] == "#" or len(set([row[i] for row in grid ])) != 1:
        continue
    for h in range(H):
        new_row = ""
        if i > 0:
            new_row += grid[h][:i]
        if i < W-1:
            new_row += grid[h][i+1:]
        grid[h] = new_row

for row in grid:
    print(row)
