h, w = [int(n) for n in input().split()]
grid = [input() for _ in range(h)]
row_hashs = set()
column_hashs = set()

for i, row in enumerate(grid):
    for j, ch in enumerate(row):
        if ch == '#':
            row_hashs.add(i)
            column_hashs.add(j)

new_grid = []

for i, row in enumerate(grid):
    if i not in row_hashs:
        continue
    new_grid.append([])
    for j, ch in enumerate(row):
        if j not in column_hashs:
            continue
        new_grid[-1].append(ch)
    new_grid[-1] = "".join(new_grid[-1])


print("\n".join(new_grid))
# print(*new_grid, sep="\n")