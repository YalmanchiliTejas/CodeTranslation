H,W = map(int,input().split())
grid = []
for i in range(H):
    row = list(input())
    grid.append(row)
while True:
    r_change = False
    for q in range(len(grid)):
        if "#" not in grid[q]:
            del grid[q]
            r_change = True
            break
    if not r_change:
        break
while True:
    c_change = False
    for k in range(len(grid[0])):
        if "#" not in [row[k] for row in grid]:
            grid = [[row[p] for p in range(len(row)) if p != k] for row in grid]
            c_change = True
            break
    if not c_change:
        break
for row in grid:
    print("".join(row))