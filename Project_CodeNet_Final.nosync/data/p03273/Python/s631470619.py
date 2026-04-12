h, w = map(int, input().split())
grid = []
for i in range(h):
    a = list(input())
    for j in range(w):
        if a[j] == "#":
            grid.append(a)
            break
        else:
            continue

col = [i for i in range(len(grid[0]))]
for j in range(len(grid[0])):
    for i in range(len(grid)):
        if grid[i][j] == "#":
            break
    else:
        continue
    col.remove(j)

for g in grid:
    for c in col[::-1]:
        g.pop(c)
    print(*g, sep='')