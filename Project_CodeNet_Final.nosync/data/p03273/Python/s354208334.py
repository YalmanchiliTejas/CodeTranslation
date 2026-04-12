h, w = map(int, input().split())
grid = [list(input()) for _ in range(h)]
row_white = []
column_white = []

for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            break
        if j == w - 1:
            row_white.append(i)
for i in range(len(row_white)):
    grid.pop(row_white[i] - i)

h = len(grid)
for j in range(w):
    for i in range(h):
        if grid[i][j] == '#':
            break
        if i == h - 1:
            column_white.append(j)
for j in range(len(column_white)):
    for i in range(h):
        del grid[i][column_white[j] - j]
for i in range(h):
    print(*grid[i], sep='')