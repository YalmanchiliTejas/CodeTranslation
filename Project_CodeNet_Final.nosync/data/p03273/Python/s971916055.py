h, w = [ int(i) for i in input().split()]
grid = [list(input()) for j in range(h)]
isOkColumn = [ 0 for i in range(w)]
isOkRow = [0 for i in range(h)]

for r in range(h):
    if '#' in grid[r]:
        isOkRow[r] = 1
    for c in range(w):
        if grid[r][c] == '#':
            isOkColumn[c] = 1

for r in range(h):
    if isOkRow[r] == 1:
        r_g = ''
        for c in range(w):
            if isOkRow[r] == 1 and isOkColumn[c] == 1:
                r_g += grid[r][c]
        print(r_g)
