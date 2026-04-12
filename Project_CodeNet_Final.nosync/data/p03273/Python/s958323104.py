h, w = map(int, input().split())
grid = [list(input()) for _ in range(h)]

rows = [0] * h
for i in range(h):
    for j in range(w):
        rows[i] |= (grid[i][j] == '#')

cols = [0] * w
for j in range(w):
    for i in range(h):
        cols[j] |= (grid[i][j] == '#')

for i in range(h):
    if not rows[i]:
        continue
    for j in range(w):
        if not cols[j]:
            continue
        print(grid[i][j], end='')
    print()