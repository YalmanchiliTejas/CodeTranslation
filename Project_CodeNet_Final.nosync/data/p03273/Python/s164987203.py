H, W = map(int, input().split())
grid = []
for i in range(H):
    row = list(input())
    grid.append(row)
row_flags = [1] * H
col_flags = [1] * W

for i in range(H):
    t = grid[i][0]
    if t != ".":
        continue
    for j in range(1, W):
        if grid[i][j] != t:
            break
    else:
        row_flags[i] = 0
for j in range(W):
    t = grid[0][j]
    if t != ".":
        continue
    for i in range(1, H):
        if grid[i][j] != t:
            break
    else:
        col_flags[j] = 0

for i in range(H):
    if not row_flags[i]:
        continue
    for j in range(W):
        if not col_flags[j]:
            continue
        print(grid[i][j], end="")
    print()
