h, w = map(int, input().split())

grid = []

for _ in range(h):
    line = input().rstrip()
    if line.count('#') == 0:
        continue
    grid.append(line)


remove_columns = []

for c in range(w):
    for r in range(len(grid)):
        if grid[r][c] == '#':
            break
    else:
        remove_columns.append(c)

for line in grid:
    for i, l in enumerate(line):
        if i not in remove_columns:
            print(l, end='')
    print()

